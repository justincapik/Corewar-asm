/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:39:38 by jucapik           #+#    #+#             */
/*   Updated: 2019/05/07 11:39:33 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	get_command_type(t_tokens *tok, int *arg, int line_nb)
{
	int		i;
	t_onet	*onet;

	onet = tok->allt;
	if (*arg == 1)
		onet = onet->next;
	if (onet->sep_after == true)
	{
		error_message("ERROR: invalde separator after command", line_nb);
		return (error);
	}
	i = 0;
	while (g_op_tab[i].name != 0)
	{
		if (ft_strcmp(onet->str, g_op_tab[i].name) == 0)
		{
			tok->cmd = i;
			onet->type = T_CMD;
			*arg += 1;
			return (true);
		}
		++i;
	}
	error_message("ERROR: invalde commande", line_nb);
	return (error);
}

static t_bool	check_label(t_tokens *tok, int *arg, int line_nb)
{
	int		size;
	t_onet	*onet;
	char	*str;

	onet = tok->allt;
	str = onet->str;
	size = (int)ft_strlen(str);
	if (str[size - 1] == LABEL_CHAR)
	{
		onet->type = T_LAB;
		tok->label = str;
		*arg += 1;
		if (onet->sep_after == true)
		{
			error_message("ERROR: invalid separator after label", line_nb);
			return (error);
		}
		if (onet->next == NULL)
			return (false);
	}
	return (true);
}

static t_onet	*set_onet(t_tokens *tok, int arg)
{
	t_onet *onet;

	onet = tok->allt;
	while (arg > 0)
	{
		onet = onet->next;
		--arg;
	}
	return (onet);
}

t_bool			parsing(t_tokens *tok, int line_nb)
{
	int		arg;
	t_onet	*onet;
	t_bool	res;

	arg = 0;
	if ((res = check_label(tok, &arg, line_nb)) == false)
		return (false);
	else if (res == error)
		return (error);
	if (get_command_type(tok, &arg, line_nb) == error)
		return (error);
	onet = set_onet(tok, arg);
	arg = 0;
	while (onet != NULL)
	{
		if (syntax_analysis(onet, line_nb) == error)
			return (error);
		onet = onet->next;
		++arg;
	}
	if (check_errors(tok, arg, line_nb) != true)
		return (error);
	get_token_size(tok);
	return (true);
}
