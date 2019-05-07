/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:16:19 by jucapik           #+#    #+#             */
/*   Updated: 2019/05/07 14:02:23 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_onet			*create_onet(void)
{
	t_onet		*o;

	if ((o = (t_onet *)malloc(sizeof(t_onet))) == NULL)
		return (NULL);
	o->sep_after = error;
	o->type = T_NO_TYPE;
	o->next = NULL;
	o->str = NULL;
	o->ptr_to_label = NULL;
	return (o);
}

t_tokens		*create_tokens(void)
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

static t_data	*create_data_helper(t_data *data, int ac, char **av)
{
	char		*name;

	if ((name = get_file(ac, av)) == NULL)
	{
		ft_putstr_fd("ERROR: invalid file name\n", 2);
		free_data(data);
		return (NULL);
	}
	if ((data->code_file_fd = open(name, O_RDONLY)) <= -1)
	{
		ft_putstr_fd("ERROR: failed to open file\n", 2);
		free_data(data);
		return (NULL);
	}
	return (data);
}

t_data			*create_data(int ac, char **av)
{
	t_data		*data;

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
	return (create_data_helper(data, ac, av));
}
