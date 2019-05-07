/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_stx_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:19:45 by jucapik           #+#    #+#             */
/*   Updated: 2019/05/07 13:56:59 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	set_register(t_onet *onet, int line_nb)
{
	int		i;

	i = 0;
	onet->type = T_REG;
	++i;
	onet->val = ft_atoi((onet->str) + i);
	while (onet->str[i] >= '0' && onet->str[i] <= '9')
		++i;
	if (onet->str[i] != '\0')
	{
		error_message("ERROR: invalide register paramater", line_nb);
		return (error);
	}
	if (onet->val < 1 || onet->val > REG_NUMBER)
	{
		error_message("ERROR: invalide register number", line_nb);
		return (error);
	}
	return (true);
}

static t_bool	set_direct_nolabel(t_onet *onet, int line_nb)
{
	int		i;

	i = 0;
	onet->type = T_DIR;
	++i;
	onet->val = ft_atoi((onet->str) + i);
	if (onet->str[i] == '-' || onet->str[i] == '+')
		++i;
	while (onet->str[i] >= '0' && onet->str[i] <= '9')
		++i;
	if (onet->str[i] != '\0')
	{
		error_message("ERROR: invalide direct number", line_nb);
		return (error);
	}
	return (true);
}

static t_bool	set_index_nolabel(t_onet *onet, int line_nb)
{
	int		i;

	i = 0;
	onet->type = T_IND;
	onet->val = ft_atoi((onet->str) + i);
	if (onet->str[i] == '-' || onet->str[i] == '+')
		++i;
	while (onet->str[i] >= '0' && onet->str[i] <= '9')
		++i;
	if (onet->str[i] != '\0')
	{
		error_message("ERROR: invalide index number", line_nb);
		return (error);
	}
	return (true);
}

t_bool			syntax_analysis(t_onet *onet, int line_nb)
{
	if (onet->str == NULL || onet->str[0] == '\0'
			|| ((int)ft_strlen(onet->str) == 1 && !(onet->str[0] >= '0'
					&& onet->str[0] <= '9'))
			|| (onet->next == NULL && onet->sep_after == true)
			|| (onet->next != NULL && onet->sep_after == false))
	{
		error_message("ERROR: invalide parameter", line_nb);
		return (error);
	}
	if (onet->str[0] == 'r')
		return (set_register(onet, line_nb));
	else if (onet->str[0] == DIRECT_CHAR && onet->str[1] != LABEL_CHAR)
		return (set_direct_nolabel(onet, line_nb));
	else if (onet->str[0] != DIRECT_CHAR && onet->str[0] != LABEL_CHAR)
		return (set_index_nolabel(onet, line_nb));
	else if (onet->str[0] != DIRECT_CHAR && onet->str[0] == LABEL_CHAR)
		return (set_index_label(onet, line_nb));
	else if (onet->str[0] == DIRECT_CHAR && onet->str[1] == LABEL_CHAR)
		return (set_direct_label(onet, line_nb));
	error_message("ERROR: invalide parameter", line_nb);
	return (error);
}
