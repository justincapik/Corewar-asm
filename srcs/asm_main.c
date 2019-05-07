/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:21:27 by jucapik           #+#    #+#             */
/*   Updated: 2019/05/07 11:37:39 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*get_file(int ac, char **av)
{
	char	*str;
	int		size;
	int		i;

	i = 1;
	str = NULL;
	while (i < ac)
	{
		size = (int)ft_strlen(av[i]);
		if (av[i][size - 1] == 's' && av[i][size - 2] == '.')
			str = av[i];
		++i;
	}
	return (str);
}

static int		main_helper(int ac, char **av, t_data *data)
{
	data->size = get_size_prog(data->tokens);
	if (connect_labels(data->tokens) != true)
	{
		free_data(data);
		return (-1);
	}
	if (write_file(data, get_file(ac, av)) == error)
	{
		free_data(data);
		return (-1);
	}
	verbose(data, ac, av);
	free_data(data);
	return (0);
}

int				main(int ac, char **av)
{
	t_data		*data;

	if (file_error(ac, av) == -1)
		return (-1);
	if ((data = create_data(ac, av)) == NULL)
		return (-1);
	if (get_head(data) != true)
	{
		free_data(data);
		return (-1);
	}
	if ((data->tokens = read_lines(data)) == NULL)
	{
		free_data(data);
		return (-1);
	}
	return (main_helper(ac, av, data));
}
