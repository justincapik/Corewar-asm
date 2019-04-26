/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_verbose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:51:59 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/26 14:29:48 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	check_verbose(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-v") == 0 || ft_strcmp(av[i], "--verbose") == 0)
			return (true);
		++i;
	}
	return (false);
}

static void		print_info(t_data *data)
{
	ft_putstr("name => \"");
	ft_putstr(data->name);
	ft_putstr("\"\n");
	ft_putstr("comment => \"");
	ft_putstr(data->comment);
	ft_putstr("\"\n");
	ft_putstr("size => ");
	ft_putnbr(data->size);
	ft_putchar('\n');
	ft_putchar('\n');
}

static void		print_tokens(t_onet *onet)
{
	if (onet->type & T_CMD)
		onet = onet->next;
	while (onet != NULL)
	{
		if (onet->type & T_LAB)
		{
			ft_putchar('(');
			ft_putstr(onet->ptr_to_label->label);
			ft_putstr(")->");
		}
		if (onet->type & T_REG)
			ft_putstr("REG: ");
		else if (onet->type & T_IND)
			ft_putstr("IND: ");
		else if (onet->type & T_DIR)
			ft_putstr("DIR: ");
		else if (onet->type & T_CMD)
			ft_putstr("CMD: ");
		else if (onet->type & T_NO_TYPE)
			ft_putstr("NO_TYPE: ");
		ft_putnbr(onet->val);
		ft_putchar('\t');
		onet = onet->next;
	}//TODO add tabultions according to label size
}

void			verbose(t_data *data, int ac, char **av)
{
	t_tokens    *tok;

	if (check_verbose(ac, av) == false)
		return ;
	tok = data->tokens;
	print_info(data);
	while (tok != NULL)
	{
		ft_putstr("memory address: ");
		ft_putnbr(tok->mem_addr);
		if (tok->label != NULL)
		{
			ft_putstr(", label: ");
			ft_putstr(tok->label);
		}
		ft_putchar('\n');
		if (tok->cmd != NONE)
		{
			ft_putstr(g_op_tab[tok->cmd].name);
			if (ft_strlen(g_op_tab[tok->cmd].name) < 4)
				ft_putchar('\t');
			ft_putchar('\t');
			print_tokens(tok->allt->next);
			ft_putstr("\n\n");
		}
		tok = tok->next;
	}
}
