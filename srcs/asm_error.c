/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:26:09 by jucapik           #+#    #+#             */
/*   Updated: 2019/05/07 13:53:14 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool		gnl_error_bool(void)
{
	ft_putstr_fd("ERROR: error while reading file\n", 2);
	return (error);
}

t_tokens	*gnl_error_null(t_tokens *tok)
{
	free_tokens(tok);
	ft_putstr_fd("ERROR: error while reading file\n", 2);
	return (NULL);
}

void		size_error_message(int max_size, char *type)
{
	ft_putstr_fd("ERROR: invalude syntax on ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd(" line (max length ", 2);
	ft_putnbr_fd(max_size, 2);
	ft_putstr_fd(")\n", 2);
}

void		error_message(char *str, int line_nb)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" on line ", 2);
	ft_putnbr_fd(line_nb, 2);
	ft_putchar_fd('\n', 2);
}

int			file_error(int ac, char **av)
{
	if (ac <= 1)
	{
		write(2, "Usage: ", 7);
		write(2, av[0], (int)ft_strlen(av[0]));
		write(2, " [-v] <sourcefile.s>\n", 21);
		return (-1);
	}
	return (0);
}
