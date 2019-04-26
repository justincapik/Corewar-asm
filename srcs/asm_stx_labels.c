/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_stx_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:25:14 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/24 14:36:45 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool			set_index_label(t_onet *onet, int line_nb)
{
	int		i;

	i = 0;
	onet->type = T_IND | T_LAB;
	onet->val = ft_atoi((onet->str) + (++i));
	while (onet->str[i] != '\0'
			&& ft_strchr(LABEL_CHARS, onet->str[i]) != NULL)
		++i;
	if (onet->str[i] != '\0')
	{
		ft_putstr("ERROR: invalide index label on line ");
		ft_putnbr(line_nb);
		ft_putchar('\n');
		return (error);
	}
	return (true);
}

t_bool			set_direct_label(t_onet *onet, int line_nb)
{
	int		i;

	i = 0;
	onet->type = T_DIR | T_LAB;
	onet->val = ft_atoi((onet->str) + i);
	i += 2;
	while (onet->str[i] != '\0'
			&& ft_strchr(LABEL_CHARS, onet->str[i]) != NULL)
		++i;
	if (onet->str[i] != '\0')
	{
		ft_putstr("ERROR: invalide direct label on line ");
		ft_putnbr(line_nb);
		ft_putchar('\n');
		return (error);
	}
	return (true);
}
