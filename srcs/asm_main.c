/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:21:27 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/20 17:56:28 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		usage(char *name)
{
	write(1, "Usage: ", 9);
	write(1, name, ft_strlen(name));
	write(1, " <sourcefile.s>\n", 16);
	return (-1);
}

int		main(int ac, char **av)
{
	if (ft_strcmp(av[0], "./asm") != 0)
	{
		write(1, "Error: wrong executable name\n", 29);
		return (-1);
	}
	if (ac <= 1)
		return (usage(av[0]));

	//ouvrir et chequer le nom du fichier
	//creer les token, ou un moyen de les interpreter a partir de op.c
	//ligne par ligne faire
	//	la tokenisation (a voir comment enregistrer), faire les messages d'erreur a l'erreur
	//	analyse syntaxique des tokens, faire les messages d'erreur a l'erreur
	//appliquer les bonnes adresses et/ou pointeurs pour les %:label
	//transcrire ligne par ligne dans le fichier
	return (0);
}
