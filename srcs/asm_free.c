/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:31:29 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/10 18:27:45 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_data(t_data *data)
{
	if (data->name != NULL)
		free(data->name);
	if (data->comment != NULL)
		free(data->comment);
	free(data);
	//free_cmds(data->cmds);
}
