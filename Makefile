# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 16:29:58 by sumsong           #+#    #+#              #
#    Updated: 2022/10/04 16:31:28 by sumsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC 			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror -g
CCFLAGS_G	=	-Wall -Wextra -Werror -g
SANITIZER	=	-fsanitize=address
IREADLINE	=	-I/Users/sumsong/.brew/opt/readline/include
LREADLINE	=	-L/Users/sumsong/.brew/opt/readline/lib
RM			=	rm -f

SRC_DIR		=	./srcs/
SRC			=	main.c \
				init/env_handler.c init/signal_handler.c \
				tokenize/tokenize.c tokenize/tokenize_utils.c tokenize/tokenize_case1.c tokenize/tokenize_case2.c \
				tree_structure/make_tree.c tree_structure/make_tree_redir_node.c \
				parser/tree_parser.c parser/tree_parser_heredoc.c parser/delquote_expand.c parser/delquote_utils.c \
				execute/execute.c execute/cmd_action.c execute/child_pipe.c execute/open_redir_file.c execute/path.c execute/execute_builtin.c \
				utils/utils1.c utils/utils2.c utils/utils_cleaners.c utils/utils_system.c utils/utils_list.c utils/utils_envir_error.c \
				utils/utils_atoi.c utils/utils_itoa.c utils/utils_split.c utils/utils_strjoin.c utils/utils_isalnum.c

BUILTIN_DIR	=	./builtin_srcs/
BUILTIN		=	builtin_pwd.c \
				builtin_cd.c \
				builtin_echo.c \
				builtin_env.c \
				builtin_exit.c \
				builtin_export.c \
				builtin_unset.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC)) \
				$(addprefix $(BUILTIN_DIR), $(BUILTIN))
BUILTIN_SRCS=	$(addprefix $(BUILTIN_DIR), $(BUILTIN))
OBJS	=	$(SRCS:.c=.o)

ifdef	WITH_BONUS
	OBJECTS	=	$(OBJS_B)
else
	OBJECTS	=	$(OBJS)
endif

all	:	$(NAME)

bonus	:
	make WITH_BONUS=1 all

.c.o	:
	$(CC) $(CCFLAGS_G) $(IREADLINE) -c -o $@ $<

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LREADLINE) -lreadline -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

lldb: all
	gcc $(OBJS) $(CCFLAGS_G) $(LREADLINE) -lreadline -o $(NAME)

sani: $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(SANITIZER) $(LREADLINE) -lreadline -o $(NAME)

re	:	fclean all

.PHONY	:	all bonus clean fclean re lldb sani
