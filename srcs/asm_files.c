/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:16:19 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/21 14:11:39 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_data		*create_data(int ac, char **av)
{
	t_data		*data;
	char		*name;

	if ((data = (t_data *)malloc(sizeof(data))) == NULL)
	{
		write(1, "Error: malloc failed\n",
				ft_strlen("Error, malloc failed\n"));
		return (NULL);
	}
	name = av[ac - 1];
	if ((data->code_file_fd = open(name, O_RDONLY)) <= -1)
	{
		write(1, "Error: failed to open file\n",
				ft_strlen("Error, failed to open file\n"));
		free(data);
		return (NULL);
	}
	data->cmds = NULL;
	return (data);
}
