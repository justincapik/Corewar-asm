/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:26:09 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/10 18:08:50 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#include "asm.h"

int		file_error(int ac, char **av)
{
	if (ac <= 1)
	{
		write(1, "Usage: ", 7);
		write(1, av[0], ft_strlen(av[0]));
		write(1, " <sourcefile.s>\n", 16);
		return (-1);
	}
	return (0);
}
