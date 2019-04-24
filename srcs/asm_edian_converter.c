/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_edian_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:32:34 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/24 11:24:25 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_int(int nb, int fd)
{
	t_bec4	bec;
	int		i;

	bec.nb = nb;
	i = 3;
	while (i >= 0)
		write(fd, &(bec.oct[i--]), 1);
}

void	write_int_2b(int nb, int fd)
{
	t_bec4	bec;

	bec.nb = nb; //TODO not sure about this, maybe 0xffff
	write(fd, &(bec.oct[1]), 1);
	write(fd, &(bec.oct[0]), 1);
}

void	write_int_1b(int nb, int fd)
{
	char	c;

	c = nb % 0xff; //TODO not sure about this, maybe 0xff
	write(fd, &c, 1);
}

//TODO write converteur for number of size to bytes
