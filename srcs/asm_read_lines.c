/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_read_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:38:19 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/22 16:53:45 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#include "asm.h"

static t_onet	*get_onet(char *line, int *i)
{
	int 	j;
	t_onet	*onet;

	if ((onet = create_onet()) == NULL)
		return (NULL);
	while ((line[*i] == ' ' || line[*i] == '\t') && line[*i] != '\0')
		++(*i);
	if (line[*i] == '\0' || line[*i] == COMMENT_CHAR)
	{
		free_onet(onet);
		return (NULL);
	}
	j = 0;
	while (line[*i + j] != ' ' && line[*i + j] != '\t'
			&& line[*i + j] != SEPARATOR_CHAR && line[*i + j] != '\0')
		++j;
	onet->str = ft_strndup(line + *i, j);
	*i += j;
	while ((line[*i] == ' ' || line[*i] == '\t') && line[*i] != '\0')
		++(*i);
	*i += ((line[*i] == SEPARATOR_CHAR) ? 1 : 0);
	return (onet);
}

static t_tokens	*tokenize(char *line)
{
	int			i;
	t_onet		*onet;
	t_tokens	*tok;

	i = 0;
	onet = NULL;
	if ((tok = create_tokens()) == NULL)
		return (NULL);
	if ((tok->allt = get_onet(line, &i)) == NULL)
	{
		free_tokens(tok);
		return (NULL);
	}
	onet = tok->allt;
	while (line[i] != '\0' && onet != NULL)
	{
		onet->next = get_onet(line, &i);
		onet = onet->next;
	}
	return (tok);
}

static t_tokens	*get_base(t_data *data)
{
	char		*line;
	t_tokens	*base;

	line = NULL;
	base = NULL;
	while (base == NULL
			&& get_next_line(data->code_file_fd, &line) != 0)
	{
		if ((base = tokenize(line)) != NULL)
		{
			if (parsing(base, data->line_nb) == error)
			{
				free_tokens(base);
				free(line);
				return (NULL);
			}
		}
		free(line);
		++(data->line_nb);
	}
	return (base);
}

t_tokens		*read_lines(t_data *data)
{
	char		*line;
	t_tokens	*base;
	t_tokens	*cur;
	t_tokens	*tmp;

	line = NULL;
	if ((base = get_base(data)) == NULL)
		return (NULL);
	cur = base;
	while (get_next_line(data->code_file_fd, &line) != 0)
	{
		if ((tmp = tokenize(line)) != NULL)
		{
			if (parsing(tmp, data->line_nb) == error)
			{
				free_tokens(base);
				free(line);
				return (NULL);
			}
			cur->next = tmp;
			cur = cur->next;
		}
		free(line);
		++(data->line_nb);
	}
	return (base);
}
