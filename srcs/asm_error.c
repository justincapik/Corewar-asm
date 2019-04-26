/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:26:09 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/25 14:41:53 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	size_error_message(int max_size, char *type)
{
	ft_putstr("ERROR: invalude syntax on ");
	ft_putstr(type);
	ft_putstr(" line (max length ");
	ft_putnbr(max_size);
	ft_putstr(")\n");
}

void	error_message(char *str, int line_nb)
{
	ft_putstr(str);
	ft_putstr(" on line ");
	ft_putnbr(line_nb);
	ft_putchar('\n');
}

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
