/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:45:16 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/23 15:43:41 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_name(char *name, int fd)
{
	int		size;
	int		i;
	char	c;

	size = ft_strlen(name);
	write(fd, name, size);
	c = 0;
	i = size;
	while (i < PROG_NAME_LENGTH)
	{
		write(fd, &c, 1);
		++i;
	}
	write_int(0, fd);
}

static void	write_comment(char *comment, int fd)
{
	int		size;
	int		i;
	char	c;

	size = ft_strlen(comment);
	write(fd, comment, size);
	c = 0;
	i = size;
	while (i < COMMENT_LENGTH)
	{
		write(fd, &c, 1);
		++i;
	}
	write_int(0, fd);
}

void		write_header(t_data *data)
{
	write_int(COREWAR_EXEC_MAGIC, data->binary_file_fd);
	write_name(data->name, data->binary_file_fd);
	write_int(data->size, data->binary_file_fd);
	write_comment(data->comment, data->binary_file_fd);
}
