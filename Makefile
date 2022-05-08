# -*- Makefile -*-

#	@	target name
#	^	all dependencies
#	<	first dependencie
#	-c	create a file.o
#	-o	place the output in a file 'file.'

#target:	depenencies
#	action

NAME			= 	philophers
LIBFT			= 	libft.a

#compilation
CC 				=	gcc
CF 				=	-Wall -Wextra -Werror
CFI 			=	-I $(INCLUDE)
THREAD			=	-lpthread

LIBFT_PATH 		=	./libft/
SRC_PATH 		=	./src/
OBJ_PATH		=	./obj/
INCLUDE 		=	./include/

L_LIBFT			=	-L $(LIBFT_PATH) -lft

SRC				=	main.c\
					init_process.c\
					thread_creation.c\
					exec_philo.c\
					time.c\
					clean.c\

VPATH 			:=	$(SRC_PATH)\
					$(SRC_PATH)system\
					$(SRC_PATH)threads\
					$(SRC_PATH)init\
					$(SRC_PATH)exec\
					$(SRC_PATH)time\

OBJ				=	$(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

#common commands
RM 				=	rm -rf

#rules
$(OBJ_PATH)%.o: %.c
				@printf "\n$(CY)Generating object...$(RC)\n"
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@
				@printf "$(GR)Object ready!$(RC)"

$(NAME):		$(OBJ)
				@printf "\n$(CY)Generating libft...$(RC)\n"
				make -C $(LIBFT_PATH) $(LIBFT)
				@printf "\n$(CY)Generating minishell executable...$(RC)\n"
				$(CC) $(CF) -I $(INCLUDE) -o $(NAME) $(OBJ) $(L_LIBFT) $(THREAD)
				@printf "$(GR)Done!$(RC)\n\n"

all:			$(NAME)

re:				fclean all

clean:
				make -C $(LIBFT_PATH) clean
				$(RM) $(OBJ) $(OBJDIR)
				@printf "$(RE)minishell objects removed!$(RC)\n\n"

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)
				@printf "$(RE)Executables removed!$(RC)\n\n"

.PHONY:			all clean fclean re bonus rebonus
