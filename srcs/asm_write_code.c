/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:44:14 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/24 12:55:20 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_cmd(int cmd, int fd)
{
	char 	c;

	c = cmd;
	write(fd, &c, 1);
}

static void	write_ocp(t_onet *onet, int fd)
{
	char ocp;
	int	i;

	ocp = 0;
	i = 7;
	while (onet != NULL)
	{
		if (onet->type & T_REG)
		{
			ocp |= 1 << (--i);
			--i;
		}
		else if (onet->type & T_DIR)
		{
			ocp |= 1 << i;
			i -= 2;
		}
		else if (onet->type & T_IND)
		{
			ocp |= 1 << (i--);
			ocp |= 1 << (i--);
		}
		onet = onet->next;
	}
	write(fd, &ocp, 1);
}

void		write_line_code(t_tokens *tok, int fd)
{
	t_onet		*onet;

	write_cmd(op_tab[tok->cmd].id, fd);
	onet = tok->allt->next;
	if (tok->label != NULL)
		onet = onet->next;
	if (op_tab[tok->cmd].OCP == 1)
		write_ocp(onet, fd);
	while (onet != NULL)
	{
		if (onet->type & T_REG)
			write_int_1b(onet->val, fd);
		else if (onet->type & T_DIR && op_tab[tok->cmd].dir_type == 0)
			write_int(onet->val, fd);
		else if (onet->type & T_DIR && op_tab[tok->cmd].dir_type == 1)
			write_int_2b(onet->val, fd);
		else if (onet->type & T_IND)
			write_int_2b(onet->val, fd);
		onet = onet->next;
	}
}
//TODO labels
