/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:21:27 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/17 13:38:35 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#include "asm.h"


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

	data->tokens = read_lines(data);
	//ligne par ligne faire
	//	la tokenisation (a voir comment enregistrer),
	//	faire les messages d'erreur a l'erreur
	//	analyse syntaxique des tokens, faire les messages d'erreur a l'erreur
	//appliquer les bonnes adresses et/ou pointeurs pour les %:label
	//transcrire ligne par ligne dans le fichier
	t_tokens	*tok;
	t_onet		*onet;
	tok = data->tokens;
	dprintf(2, "name => \"%s\"\n", data->name);
	dprintf(2, "comment => \"%s\"\n", data->comment);
	while (tok != NULL)
	{
		onet = tok->allt;
		while (onet != NULL)
		{
			dprintf(2, "-%s-", onet->str);
			onet = onet->next;
		}
		dprintf(2, "\n");
		tok = tok->next;
	}
	free_data(data);
	return (0);
}
