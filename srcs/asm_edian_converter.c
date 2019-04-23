/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_edian_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:32:34 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/23 15:51:59 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_int(int nb, int fd)
{
	t_bec	bec;
	int		i;

	bec.nb = nb;
	i = 3;
	while (i >= 0)
		write(fd, &(bec.oct[i--]), 1);
}

//TODO write converteur for number of size to bytes
