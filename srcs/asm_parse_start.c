/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:31:56 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/21 18:08:59 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool		get_name(char *line, char name[PROG_NAME_LENGTH],
		t_nh_bln *check)
{
	int		i;
	int		j;
	
	i = ft_strlen(NAME_CMD_STRING);
	while (line[i] != '"' && line[i] != '\0')
		++i;
	if (line[i] == '\0')
		return (false);
	++i;
	j = 0;
	while (line[i + j] != '"' && line[i] != '\0')
		++i;
	if (line[j + i] == '\0')
		return (false);
	j = 0;
	while (line[i + j] != '"')
	{
		name[j] = line[i + j];
		++j;
	}
	name[j] = '\0';
	*check = (*check == COMMENT) ? DONE : NAME;
	return (true);
}

static t_bool		get_comment(char *line, char comment[COMMENT_LENGTH],
		t_nh_bln *check)
{
	int		i;
	int		j;
	
	i = ft_strlen(COMMENT_CMD_STRING);
	while (line[i] != '"' && line[i] != '\0')
		++i;
	if (line[i] == '\0')
		return (false);
	++i;
	j = 0;
	while (line[i + j] != '"' && line[i] != '\0')
		++i;
	if (line[j + i] == '\0')
		return (false);
	j = 0;
	while (line[i + j] != '"')
	{
		comment[j] = line[i + j];
		++j;
	}
	comment[j] = '\0';
	*check = (*check == NAME) ? DONE : COMMENT;
	return (true);
}

t_bool				get_head(t_data *data)
{
	char		*line;
	int			i;
	int			name_size;
	int			com_size;
	t_nh_bln	check;

	name_size = ft_strlen(NAME_CMD_STRING);
	com_size = ft_strlen(COMMENT_CMD_STRING);
	line = NULL;
	check = NOTHING;
	while (check != DONE && get_next_line(data->code_fd, &line) != 0)
	{
		i = 0;
		while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
			++i;
		if (ft_strncmp(NAME_CMD_STRING, line + i, name_size) == 0)
		{
			if (check == NAME || get_name(line, data->name, &check) == false)
			{
				free(line);
				return (false);
			}
		}
		if (ft_strncmp(COMMENT_CMD_STRING, line + i, comment_size) == 0)
		{
			if (check == COMMENT || get_comment(line, data->comment, &check)
					== false)
			{
				free(line);
				return (false);
			}
		}
	}
	return (true);
}
