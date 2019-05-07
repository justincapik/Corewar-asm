/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:31:29 by jucapik           #+#    #+#             */
/*   Updated: 2019/05/07 12:59:25 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_onet(t_onet *base)
{
	t_onet	*tmp;

	while (base != NULL)
	{
		tmp = base->next;
		if (base->str != NULL)
			ft_strdel(&(base->str));
		ft_memdel((void**)&base);
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
		if (base->allt != NULL)
			free_onet(base->allt);
		ft_memdel((void**)&base);
		base = cur;
	}
}

void		free_data(t_data *data)
{
	if (data != NULL)
	{
		if (data->name != NULL)
			ft_strdel(&data->name);
		if (data->comment != NULL)
			ft_strdel(&data->comment);
		if (data->tokens != NULL)
			free_tokens(data->tokens);
		ft_memdel((void **)&data);
	}
}
