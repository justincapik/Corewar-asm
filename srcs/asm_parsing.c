/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:39:38 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/17 14:29:47 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool		parsing(t_tokens *tok)
{
	int		arg;

	//check if first is label
	//get command type -> free, error message and return if invalide
	//for each memory case =>
	//	find type =>
	//		if register (ex: r12) <=> pas de '%' (DIRECT_CHAR)
	//			check if not negative or above REG_NUMBER
	//		if index <=> pas de '%' (DIRECT_CHAR)
	//			if just number 
	//				verify if is smaller than MEM_SIZE
	//			if followed by ':' (LABEL_CHAR)
	//				save name for when connecting labels
	//		if direct <=> '%' (DIRECT_CHAR)
	//			if just number 
	//				verify if is smaller than MEM_SIZE
	//			if followed by ':' (LABEL_CHAR)
	//				save name for when connecting labels
	
	//TODO error verifications in the comments above aren't perfect
	return (true);
}
