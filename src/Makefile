NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

HDR_SRC		=	../includes/pipex.h
HDR_DIR		=	/Users/auzochuk/Desktop/
HEADER		=	$(addprefix $(HDR_DIR), $(HDR_SRC))
MANDA_SRC	=	Pipex.c Pipex_utils.c Pipex_utils2.c
MANDA_DIR	=	~/Users/auzochuk/Desktop/
SRC			=	$(addprefix $(MANDA_DIR), $(MANDA_SRC))

%.o: %.c $(HEADER) Makefile
	@${CC} ${FLAGS}  -c $< -o $@

$(NAME):
	${CC} ${FLAGS} $(MANDA_SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re