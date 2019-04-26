/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:24:21 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/24 14:47:41 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	check_order(t_tokens *tok)
{
	t_onet	*onet;
	int		i;

	onet = tok->allt->next;
	if (tok->label != NULL)
		onet = onet->next;
	i = 0;
	while (onet != NULL)
	{
		if ((g_op_tab[tok->cmd].bnry_args[i] & T_REG && onet->type & T_REG)
				|| (g_op_tab[tok->cmd].bnry_args[i]
					& T_IND && onet->type & T_IND)
				|| (g_op_tab[tok->cmd].bnry_args[i]
					& T_DIR && onet->type & T_DIR)
				|| onet->type & T_CMD)
			++i;
		else
			return (error);
		onet = onet->next;
	}
	return (true);
}

t_bool			check_errors(t_tokens *tok, int arg, int line_nb)
{
	if (arg != g_op_tab[tok->cmd].nb_arg)
	{
		error_message("ERROR: invalide number of arguments", line_nb);
		return (error);
	}
	tok->line_nb = line_nb;
	if (check_order(tok) == error)
	{
		error_message("ERROR: invalide argument types", line_nb);
		return (error);
	}
	return (true);
}
