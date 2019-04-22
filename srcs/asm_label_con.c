/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_label_con.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 09:56:23 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/22 13:02:44 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	ft_strcmp_label(char *tlabel, char *olabel)
{
	int				toki;
	int				onei;

	toki = 0;
	onei = 0;
	if (tlabel == NULL || olabel == NULL)
		return (-1);
	if (olabel[onei] == DIRECT_CHAR)
		++onei;
	++onei;
	while (tlabel[toki] == olabel[onei] && tlabel[toki] && olabel[onei])
	{
		++onei;
		++toki;
	}
	if (tlabel[toki] == LABEL_CHAR && tlabel[toki + 1] == '\0'
			&& olabel[onei] == '\0')
		return (true);
	else
		return (false);
}

static t_tokens	*find_label(t_tokens *base, char *label)
{
	while (base != NULL)
	{
		if (base->label != NULL && ft_strcmp_label(base->label, label) == true)
			return (base);
		base = base->next;
	}
	return (NULL);
}

t_bool			connect_labels(t_tokens *base)
{
	t_tokens	*cur;
	t_onet		*onet;

	cur = base;	
	while (cur != NULL)
	{
		onet = cur->allt;
		if (cur->label != NULL)
			onet = onet->next;
		while (onet != NULL)
		{
			if (onet->type & T_LAB && !(onet->type & T_CMD))
			{
				if ((onet->ptr_to_label = find_label(base, onet->str)) == NULL)
				{
					error_message("ERROR: invalide label name", cur->line_nb); 
					return (error);
				}
			}
			onet = onet->next;
		}
		cur = cur->next;	
	}
	return (true);
}
