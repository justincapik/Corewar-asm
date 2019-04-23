/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:44:14 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/23 16:00:25 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		write_cmd(int cmd, int fd)
{
	char 	c;

	c = cmd;
	write(fd, &c, 1);
}

void		write_line_code(t_tokens *tok, int fd)
{

	write_cmd(op_tab[tok->cmd].id, fd);
	/*
	if (op_tab[tok->cmd].OCP == 1)
		write_ocp(tok, fd);
	*/

}

//TODO what if index is greatr than 0xffff
