#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jucapik <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 13:09:58 by jucapik           #+#    #+#              #
#    Updated: 2019/04/25 16:25:14 by jucapik          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	asm

CC			=	gcc -g


##
##		FILE DESCRIPTOR
##

INCLUDE = includes libft

SRC_PATH = srcs

SRCS =	op.c					\
		asm_main.c				\
		asm_error.c				\
		asm_malloc.c			\
		asm_free.c				\
		asm_parse_head.c		\
		asm_parse_head_helper.c	\
		asm_read_lines.c		\
		asm_parsing.c			\
		asm_stx_analysis.c		\
		asm_stx_labels.c		\
		asm_label_con.c			\
		asm_parsing_error.c		\
		asm_memory_size.c		\
		asm_binary_writing.c	\
		asm_write_header.c		\
		asm_edian_converter.c	\
		asm_write_code.c		\
		asm_verbose.c


##
##		SETTING VPATH
##

vpath %.c $(foreach dir, $(SRC_PATH), $(dir):)


##
##		DEPENDENCE DESCRIPTOR
##

IDEP = includes/asm.h

OBJ_PATH = objs

OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))


##
##		LIB DESCRIPTOR
##

LIBFT_PATH	=	libft
LIBNAME		=	ft
LIBPATH		=	$(LIBFT_PATH)
LIBHEAD		=	$(LIBFT_PATH)


##
##		FLAGS CONSTRUCTION
##

CFLAGS += -Wall -Wextra -Werror

IFLAGS = 	$(foreach dir, $(INCLUDE), -I$(dir) ) \

LFLAGS =	$(foreach path, $(LIBPATH), -L$(path) ) \
			$(foreach lib, $(LIBNAME), -l$(lib) ) \

$(OBJ_PATH)/%.o:	%.c $(IDEP)
	$(CC) -c $< -o $@ $(CFLAGS) $(IFLAGS)


all:		$(NAME)

$(NAME):	$(OBJ_PATH) $(OBJS)
	cd $(LIBPATH) && $(MAKE)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(IFLAGS) $(LFLAGS)

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

re:			fclean all

.SILENT:	all $(NAME) fclean clean re 
.PHONY:		clean fclean re
