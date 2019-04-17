/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:23:06 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/17 14:29:49 by jucapik          ###   ########.fr       */
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
	LIVE = 0,
	LD = 1,
	ST = 2,
	ADD = 3,
	SUB = 4,
	AND = 5,
	OR = 6,
	XOR = 7,
	ZJMP = 8,
	LDI = 9,
	STI = 10,
	FORK = 11,
	LLD = 12,
	LLDI = 13,
	LFORK = 14,
	AFF = 15,
	CMD_ERROR = 16
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

typedef struct s_one_token t_onet;
struct			s_one_token
{
	t_var_type	type;
	char		*str;
	int			val;
	t_onet		*next;
};

typedef struct s_tokens t_tokens;
struct			s_tokens
{
	t_cmd_type	cmd;
	char		*label; // NULL if doesn't exist
	t_onet		*allt;
	t_tokens	*next;
};

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

typedef struct	s_data
{
	int			code_file_fd;
	int			binary_file_fd;
	char		*name;
	char		*comment;
	int			size; //in bytes
	t_tokens	*tokens;
	t_op		*op_tab;
}				t_data;

/*
 ** Initialization
 */

t_onet		*create_onet(void);
t_data		*create_data(int ac, char **av);
t_tokens	*create_tokens(void);

/*
 ** Parsing
 */

t_bool		get_head(t_data *data);
t_tokens	*read_lines(t_data *data);
t_bool		parsing(t_tokens *tok);

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
void		free_tokens(t_tokens *t);
void		free_onet(t_onet *base);

/*
** Global Variables
*/

extern t_op op_tab[17];

#endif
