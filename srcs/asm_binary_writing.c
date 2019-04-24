/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_binary_writing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:50:40 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/24 12:58:29 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*create_file(t_data *data, char	*filename)
{
	char		*bnryname;
	int			size;

	size = ft_strlen(filename) + 2;
	bnryname = ft_strnew(size);
	bnryname = ft_strcpy(bnryname, filename);
	bnryname[size - 1] = 'r';
	bnryname[size - 2] = 'o';
	bnryname[size - 3] = 'c';
	if ((data->binary_file_fd = open(bnryname, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
	{
		ft_putendl("ERROR: failed to create .cor file");
		free(bnryname);
		return (NULL);
	}
	return (bnryname);
}

t_bool			write_file(t_data *data, char *filename)
{
	t_tokens	*tok;
	char		*bnryname;

	if ((bnryname = create_file(data, filename)) == NULL)
		return (error);
	write_header(data);
	tok = data->tokens;
	while (tok != NULL)
	{
		write_line_code(tok, data->binary_file_fd);
		tok = tok->next;
	}
	ft_putstr("Writing output program to ");
	ft_putendl(bnryname);
	free(bnryname);
	return (true);
}
