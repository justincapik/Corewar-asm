/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:31:56 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/18 10:37:38 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool		get_name(char *line, char *name, t_nh_bln *check)
{
	int i;
	int j;

	i = 0;
	while (line[i] != '\0' && line[i] != '"')
		++i;
	++i;
	j = 0;
	while (line[i + j] != '\0' && line[i + j] != '"')
		++j;
	if (line[i + j] == '\0' || j >= PROG_NAME_LENGTH)
		return (false);
	ft_strncpy(name, line + i, j);
	*check = (*check == NOTHING) ? NAME : DONE;
	return (true);
}

static t_bool		get_comment(char *line, char *comment, t_nh_bln *check)
{
	int i;
	int j;

	i = 0;
	while (line[i] != '\0' && line[i] != '"')
		++i;
	++i;
	j = 0;
	while (line[i + j] != '\0' && line[i + j] != '"')
		++j;
	if (line[i + j] == '\0' || j >= COMMENT_LENGTH)
		return (false);
	ft_strncpy(comment, line + i, j);
	*check = (*check == NOTHING) ? COMMENT : DONE;
	return (true);
}

static t_bool		check_to_get_both(char *line, t_data *data, t_nh_bln *check)
{
	int i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		++i;
	if (ft_strncmp(line + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		if (*check == NAME || get_name(line, data->name, check) == false)
		{
			ft_putstr("ERROR: on name line\n");
			return (false);
		}
	}
	if (ft_strncmp(line + i,
				COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		if (*check == COMMENT || get_comment(line, data->comment, check) == false)
		{
			ft_putstr("ERROR: on comment line\n");
			return (false);
		}
	}
	return (true);
}

static t_bool		return_value(t_nh_bln check)
{
	if (check == DONE)
		return (true);
	if (check == COMMENT)
	{
		ft_putstr("ERROR: no name line\n");
		return (false);
	}
	if (check == NAME)
	{
		ft_putstr("ERROR: no comment line\n");
		return (false);
	}
	ft_putstr("ERROR: no comment or name line\n");
	return (false);
}

t_bool				get_head(t_data *data)
{
	char		*line;
	t_nh_bln	check;

	line = NULL;
	check = NOTHING;
	while (check != DONE && get_next_line(data->code_file_fd, &line) != 0)
	{
		if (check_to_get_both(line, data, &check) == false)
		{
			free(line);
			return (false);
		}
		free(line);
		++(data->line_nb);
	}
	++(data->line_nb);
	return (return_value(check));
}
