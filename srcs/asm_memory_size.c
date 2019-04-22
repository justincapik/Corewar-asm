/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_memory_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:08:32 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/22 17:59:34 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_size_prog(t_tokens *base)
{
	int		size;

	size = 0;
	while (base != NULL)
	{
		base->mem_addr = size;
		size += base->size;
		base = base->next;
	}
	return (size);
}

void		get_token_size(t_tokens *tok)
{
	int		size;
	t_onet	*onet;

	size = 1;
	onet = tok->allt->next;
	if (tok->label != NULL)
		onet = onet->next;
	if (op_tab[tok->cmd].OCP == 1)
		++size;
	while (onet != NULL)
	{
		if (onet->type & T_IND)
			size += 2;
		else if (onet->type & T_DIR)
		{
			if (op_tab[tok->cmd].dir_type == 0)
				size += 2;
			else
				size += 4;
		}
		else
			size += 2;
		onet = onet->next;
	}
	tok->size = size;
}
