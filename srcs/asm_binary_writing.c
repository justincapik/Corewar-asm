/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_binary_writing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:50:40 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/22 18:16:22 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	create_file(t_data *data)
{
	if (data->binary_file_fd = open(
}

t_bool			write_file(t_data *data, char *filename)
{
	t_tokens	*tok;

	if (create_file(data, filename) == error)
		return (error);
	//write_header(data);
	tok = data->tokens;
	/*
	while (tok != NULL)
	{
		write_command(tok);
		tok = tok->next;
	}
	*/
	//write header
	//	-	magic number
	//	-	size
	//	-	name
	//	-	comment
	//write program: for each token
	//	-	command
	//	-	OCP ? (depending on op_tab[token->cmd].OCP)
	//	-	for each type of register:
	//			-	IND -> got get the 4 bytes at destinations and
	//					load them into the next 4 bytes? (yet to clear up) TODO
	//			-	REG -> just put the register number?
	//			-	DIR -> the value given, on 4 or two bytes bytes
	//			NOTE: if label just search value (if idx) or ptr (if dir)
	//			(not sure about that TODO)
	//TODO little edian to big edian function
	return (true);
}
