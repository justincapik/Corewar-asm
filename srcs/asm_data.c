/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:16:19 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/10 18:58:02 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_data		*create_data(int ac, char **av)
{
	t_data		*data;

	if ((data = (t_data *)malloc(sizeof(data))) == NULL)
	{
		write(1, "Error: malloc failed\n",
				ft_strlen("Error, malloc failed\n"));
		return (NULL);
	}
	data->name = NULL;
	data->comment = NULL;
	if ((data->name = ft_strnew(PROG_NAME_LENGTH)) == NULL
		|| (data->comment = ft_strnew(COMMENT_LENGTH)) == NULL)
	{
		free_data(data);
		return (NULL);
	}
	if ((data->code_file_fd = open(av[ac - 1], O_RDONLY)) <= -1)
	{
		write(1, "Error: failed to open file\n",
				ft_strlen("Error, failed to open file\n"));
		free(data);
		return (NULL);
	}
	data->cmds = NULL;
	return (data);
}
