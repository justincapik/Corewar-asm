/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:23:06 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/10 18:57:27 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include <fcntl.h>
# include "op.h"
# include "libft.h"

typedef enum	e_boolean
{
	false = 0,
	true = 1,
	error = -1
}				t_bool;

typedef enum	e_name_or_header_boolean
{
	NOTHING,
	NAME,
	COMMENT,
	DONE
}				t_nh_bln;

typedef enum	e_command_type
{
	FORK,
	LFORK,
	ST,
	STI,
	LD,
	LDI,
	LLD,
	LLDI,
	OR,
	XOR,
	AND,
	SUB,
	AFF,
	ZJMP
}				t_cmd_type;

typedef enum	e_variable_type
{
	REG,
	IDX,
	D2,
	D4,
	DUKNOWN,
	PTR //%:label type
}				t_var_type;

typedef struct	s_command t_cmd;
struct			s_command
{
	t_cmd_type	cmd;
	t_var_type	var1;
	int			var1_val;
	t_var_type	var2;
	int			var2_val;
	t_var_type	var3;
	int			var3_val;
	t_cmd		*next;
};

typedef struct	s_data
{
	int		code_file_fd;
	int		binary_file_fd;
	char	*name;
	char	*comment;
	int		size; //in bytes
	t_cmd	*cmds;
}				t_data;

typedef struct	s_op
{
	char		*name;
	int			nb_arg;
	int			bnry_args[3];
	int			id;
	int			cycle_count;
	char		*comment;
	t_bool		OCP; // 0 if not used, 1 if yes
	t_bool		dir_type; // 0 if none or D2, 1 if D4
}				t_op;

/*
** Initialization
*/

t_data		*create_data(int ac, char **av);

/*
** Parsing
*/

t_bool		get_head(t_data *data);

	/*
	** verifing lines
	*/



	/*
	** storing lines
	*/



/*
** Writing
*/



/*
** Errors
*/

int			file_error(int ac, char **av);

/*
** Free
*/

void		free_data(t_data *data);

#endif
