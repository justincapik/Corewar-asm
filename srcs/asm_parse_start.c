/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:31:56 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/21 17:22:08 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool		get_name(char *line, name[PROG_NAME_LENGTH], t_nh_bln check)
{
	int		i;

	if (*check == NAME)
		return (false);
	if (*check == 

t_bool				get_head(t_data *data)
{
	char		*line;
	int			i;
	int			name_size;
	int			com_size;
	t_nh_bln	check;

	name_size = ft_strlen(NAME_CMD_STRING);
	com_size = ft_strlen(COMMENT_CMD_SIZE);
	line = NULL;
	check = NOTHING;
	while (check != DONE && get_next_line(data->code_fd, &line) != 0)
	{
		i = 0;
		while (line[i] == ' ' || line[i] == '\t')
			++i;
		if (ft_strncmp(NAME_CMD_STRING, line + i, name_size) == 0)
			if (get_name(line, data->name, &check) == false)
				free_all(data, 1);


	}
	return (true);
}
