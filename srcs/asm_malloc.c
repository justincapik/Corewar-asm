/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:16:19 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/19 10:24:00 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_onet		*create_onet(void)
{
	t_onet		*o;

	if ((o = (t_onet *)malloc(sizeof(t_onet))) == NULL)
		return (NULL);
	o->type = T_NO_TYPE;
	o->next = NULL;
	o->str = NULL;
	o->ptr_to_label = NULL;
	return (o);
}

t_tokens	*create_tokens(void)
{
	t_tokens	*t;

	if ((t = (t_tokens *)malloc(sizeof(t_tokens))) == NULL)
		return (NULL);
	t->cmd = NONE;
	t->label = NULL;
	t->allt = NULL;
	t->next = NULL;
	return (t);
}

t_data		*create_data(int ac, char **av)
{
	t_data		*data;
	int			size;

	if ((data = (t_data *)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	data->line_nb = 0;
	data->name = NULL;
	data->comment = NULL;
	data->tokens = NULL;
	if ((data->name = ft_strnew(PROG_NAME_LENGTH)) == NULL)
	{
		free_data(data);
		return (NULL);
	}
	if ((data->comment = ft_strnew(COMMENT_LENGTH)) == NULL)
	{
		free_data(data);
		return (NULL);
	}
	size = ft_strlen(av[ac - 1]);
	if (av[ac - 1][size - 1] != 's' || av[ac - 1][size - 2] != '.')
	{
		write(1, "ERROR: invalid file name\n",
				ft_strlen("ERROR: invalid file name\n"));
		free_data(data);
		return (NULL);
	}
	if ((data->code_file_fd = open(av[ac - 1], O_RDONLY)) <= -1)
	{
		write(1, "ERROR: failed to open file\n",
				ft_strlen("Error, failed to open file\n"));
		free_data(data);
		return (NULL);
	}
	return (data);
}
