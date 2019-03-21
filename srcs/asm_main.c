/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:21:27 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/21 17:18:22 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	t_data		*data;

	if (file_error(ac, av) == -1)
		return (-1);
	if ((data = create_data(ac, av)) == NULL)
		return (-1);
	if (get_head(data) != true)
		return (-1);
	//ligne par ligne faire
	//	la tokenisation (a voir comment enregistrer), faire les messages d'erreur a l'erreur
	//	analyse syntaxique des tokens, faire les messages d'erreur a l'erreur
	//appliquer les bonnes adresses et/ou pointeurs pour les %:label
	//transcrire ligne par ligne dans le fichier
	free_all(data, 0);
	return (0);
}
