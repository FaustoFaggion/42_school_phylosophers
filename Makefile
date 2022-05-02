# -*- Makefile -*-

#	@	target name
#	^	all dependencies
#	<	first dependencie
#	-c	create a file.o
#	-o	place the output in a file 'file.'

#target:	depenencies
#	action

NAME		= 	philosophers
CC			=	gcc
CF			=	-Wall -Wextra -Werror

# Includes
I_LIBFT		= 	-I ./libft
I_PHIL		=	-I ./include

# PATH
SRC_PATH	=	src/
OBJ_PATH	=	obj/
LIBFT_PATH	=	libft/

# SRC
SRC_FILES	=	main.c\
				chk_args.c\

SRC			=	$(addprefix $(SRC_PATH), $(SRC_FILES))

# OBJ
OBJ_FILES	=	$(SRC:$(SRC_PATH)%.c=%.o)
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))


all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CF) $(OBJ) -o $@ $(I_LIBFT) $(I_PHIL)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(OBJ_PATH)
	$(CC) $(CF) -c $^ -o $@ $(I_LIBFT) $(I_PHIL)

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_PATH)
	
fclean:	clean
	rm -rf $(NAME)
