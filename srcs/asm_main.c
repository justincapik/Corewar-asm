/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:21:27 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/25 18:58:43 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_file(int ac, char **av)
{
	char	*str;
	int		size;
	int		i;

	i = 1;
	str = NULL;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		if (av[i][size - 1] == 's' && av[i][size - 2] == '.')
			str = av[i];
		++i;
	}
	return (str);
}

int		main(int ac, char **av)
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
	write(1, "1\n", 2);
	if ((data->tokens = read_lines(data)) == NULL)
	{
		free_data(data);
		return (-1);
	}
	write(1, "2\n", 2);
	data->size = get_size_prog(data->tokens);
	write(1, "3\n", 2);
	if (connect_labels(data->tokens) != true)
	{
		free_data(data);
		return (-1);
	}
	write(1, "4\n", 2);
	if (write_file(data, get_file(ac, av)) == error)
	{
		free_data(data);
		return (-1);
	}
	write(1, "5\n", 2);
	verbose(data, ac, av);
	free_data(data);
	return (0);
}

//TODO
// In parsing:
// 		- make taking label independant from the rest
// 		- always appends to the next command (?) (can be done in connections?)
// 		- if at end, make special case?
// In connecting labels:
// 		- change find_label() to look for the next token of code after
// 			after finding the label
// In mem_size:
// 		- check if there is not just the label
// In writing:
// 		- don't write if it's just a label
