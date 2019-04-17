/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:31:29 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/17 13:43:06 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#include "asm.h"

void		free_onet(t_onet *base)
{
	t_onet	*tmp;

	while (base != NULL)
	{
		tmp = base->next;
		if (base->str != NULL)
			free(base->str);
		free(base);
		base = tmp;
	}
}

void		free_tokens(t_tokens *base)
{
	t_tokens *cur;

	cur = base;
	while (cur != NULL)
	{
		cur = base->next;
		if (base->label != NULL)
			free(base->label);
		if (base->allt != NULL)
			free_onet(base->allt);
		free(base);
		base = cur;
	}
}

void		free_data(t_data *data)
{
	
	if (data->name != NULL)
		free(data->name);
	if (data->comment != NULL)
		free(data->comment);
	if (data->tokens != NULL)
		free_tokens(data->tokens);
	free(data);
}
