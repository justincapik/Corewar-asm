/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_head_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:15:00 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/29 13:43:09 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool		return_head_value(t_nh_bln check)
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

t_bool		get_ongoing_name(char *name, char *line, t_nh_bln *check)
{
	int		i;
	int		size;

	i = 0;
	while (line[i] != '\0' && line[i] != '\"')
		++i;
	size = ft_strlen(name);
	if (size + i > PROG_NAME_LENGTH || (size + i == PROG_NAME_LENGTH
				&& line[i] == '\0'))
	{
		size_error_message(PROG_NAME_LENGTH, "name");
		return (false);
	}
	ft_strncpy(name + size, line, i);
	if (line[i] == '\"')
		*check = (*check == ONGOING_NAME) ? NAME : DONE;
	else
		name[size + i] = '\n';
	return (true);
}

t_bool		get_ongoing_comment(char *comment, char *line, t_nh_bln *check)
{
	int		i;
	int		size;

	i = 0;
	while (line[i] != '\0' && line[i] != '\"')
		++i;
	size = ft_strlen(comment);
	if (size + i > COMMENT_LENGTH || (size + i == COMMENT_LENGTH
				&& line[i] == '\0'))
	{
		size_error_message(COMMENT_LENGTH, "comment");
		return (false);
	}
	ft_strncpy(comment + size, line, i);
	if (line[i] == '\"')
		*check = (*check == ONGOING_COMMENT) ? COMMENT : DONE;
	else
		comment[size + i] = '\n';
	return (true);
}
