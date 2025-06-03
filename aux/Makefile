
# Project files
SRCS		=	ft_putstr_fd.c ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isprintable.c \
				ft_bzero.c ft_calloc.c \
				ft_countstr.c ft_find_char.c ft_strcmp.c ft_strncmp.c ft_split.c ft_split2.c ft_strchr.c \
				ft_strdup.c ft_strjoin.c ft_strjoin_var.c ft_strlcpy.c ft_strcpy.c ft_strlen.c ft_strrchr.c \
				ft_substr.c ft_wordlen.c ft_itoa.c ft_atoi.c ft_atoll.c\
				ft_printf.c ft_format_type.c ft_print_adr.c ft_print_char.c ft_print_digit.c ft_print_hexa.c ft_print_string.c ft_print_string.c \
				get_next_line.c get_next_line_utils.c

OBJ_DIR		=	./object/
OBJS		=	${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}

#Build settings

NAME		=	aux.a
RM			=	rm -rf
LIBC		=	ar -rcs
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
MAKEFLAGS	+=	--no-print-directory

all:			compile ${NAME}

compile:
				@echo "Compiling $(NAME)"

${NAME}:		${OBJS}
				@${LIBC} ${NAME} ${OBJS}

${OBJ_DIR}%.o:	%.c
				@mkdir -p ${OBJ_DIR}
				@${CC} ${FLAGS} -I./ -c $< -o $@

fclean:			clean
				@${RM} ${NAME}
				@echo "aux - Removing aux.a"

clean:
				@${RM} ${OBJS}
				@${RM} ${OBJ_DIR}
				@echo "aux - Removing aux objects files"

re:				fclean all

.PHONY:			all compile clean fclean re
