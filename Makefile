NAME			=	philosophers

PATH_LIBFT		=	./libft
LIBFT			=	$(PATH_LIBFT)/libft.a

I_LIBFT			=	-I ./libft
I_PHILO			=	-I ./include

CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra

SRC_DIR			=	src
SRC_FILES		=	main.c\
					chk_args.c\

SRC				=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR			=	objects
OBJ				=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:	$(NAME)

bonus:	$(NAME_BONUS)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(I_PHILO) $(I_LIBFT)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(I_PHILO) $(I_LIBFT)

$(LIBFT):
	make -C $(PATH_LIBFT)

$(OBJ_DIR):
	mkdir objects

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)
	make -C $(PATH_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

run:
	make  && ./philosophers 1 2 3 4 5

valgrind:
	make re && valgrind --leak-check=full --show-leak-kinds=all ./minishell
