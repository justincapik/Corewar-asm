/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:39:38 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/22 13:02:43 by jucapik          ###   ########.fr       */
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
	i = 0;
	while (op_tab[i].name != 0)
	{
		if (ft_strcmp(onet->str, op_tab[i].name) == 0)
		{
			tok->cmd = i;
			onet->type = T_CMD;
			*arg += 1;
			return (true);
		}
		++i;
	}
	ft_putstr("ERROR: invalide command on line ");
	ft_putnbr(line_nb);
	ft_putchar('\n');
	tok->cmd = CMD_ERROR;
	return (error);
}

static void		check_label(t_tokens *tok, int *arg)
{
	int		size;
	t_onet	*onet;
	char	*str;

	onet = tok->allt;
	str = onet->str;
	size = ft_strlen(str);
	if (str[size - 1] == LABEL_CHAR)
	{
		onet->type = T_LAB;
		tok->label = str;
		*arg += 1;
	}
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

	arg = 0;
	check_label(tok, &arg);
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
	if (arg != op_tab[tok->cmd].nb_arg)
	{
		error_message("ERROR: invalide number of arguments", line_nb);
		return (error);
	}
	tok->line_nb = line_nb;
	return (true);
}
