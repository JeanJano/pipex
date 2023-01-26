SRCS		= 	src/pipex.c \
				src/init.c \
				src/parsing.c \
				src/free.c \
				src/error.c

SRCS_BONUS	=	src_bonus/pipex_bonus.c \
				src_bonus/init_bonus.c \
				src_bonus/parsing_bonus.c \
				src_bonus/free_bonus.c \
				src_bonus/error_bonus.c \
				src_bonus/lst_bonus.c \
				src_bonus/path_bonus.c \
				src_bonus/utils_bonus.c \
				src_bonus/here_doc.c

NAME		= pipex

NAME_BONUS	= .pipex_bonus

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -g

INCLUDES	= -Llibft -lft -I libft

.c.o:
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C libft --no-print-directory
			${CC} ${CFLAGS} ${OBJS} ${INCLUDES} -o $(NAME)

$(NAME_BONUS):	${OBJS_BONUS} 
			make -C libft --no-print-directory
			${CC} ${CFLAGS} ${OBJS_BONUS} ${INCLUDES} -o $(NAME_BONUS)
			@cp .pipex_bonus pipex

all:		$(NAME)

clean:
			make clean -C libft --no-print-directory
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			make fclean -C libft --no-print-directory
			rm -f $(NAME) $(NAME_BONUS)

re:			fclean all

bonus:		$(NAME_BONUS)

.PHONY:		all clean fclean re bonus
