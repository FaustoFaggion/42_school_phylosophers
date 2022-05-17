# -*- Makefile -*-

#	@	target name
#	^	all dependencies
#	<	first dependencie
#	-c	create a file.o
#	-o	place the output in a file 'file.'

#target:	depenencies
#	action

NAME			= 	philo
LIBFT			= 	libft.a

#compilation
CC 				=	gcc
CF 				=	-Wall -Wextra -Werror
CFI 			=	-I $(INCLUDE_PATH)
THREAD			=	-lpthread

LIBFT_PATH 		=	./libft/
SRC_PATH 		=	./src/
OBJ_PATH		=	./obj/
INCLUDE_PATH 	=	./include/

L_LIBFT			=	-L $(LIBFT_PATH) -lft

INCLUDE			=	philosophers.h

SRC				=	main.c\
					init_process.c\
					init_process_utils.c\
					setup_table.c\
					create_philo.c\
					control_lunch.c\
					wait_and_destroy.c\
					lunch.c\
					lunch_actions.c\
					time.c\
					clean.c\

OBJ				=	$(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))


NAME_BONUS		= 	philo_bonus

INCLUDE_BONUS	=	philosophers_bonus.h

SRC_PATH_BONUS	=	./bonus_src/

OBJ_PATH_BONUS	=	./bonus_obj/

SRC_BONUS		=	main_bonus.c\
					init_process_bonus.c\
					setup_table_bonus.c\
					#create_philo.c\
					control_lunch.c\
					wait_and_destroy.c\
					lunch.c\
					lunch_actions.c\
					time.c\
					clean.c\

OBJ_BONUS		=	$(addprefix $(OBJ_PATH_BONUS), $(notdir $(SRC_BONUS:.c=.o)))

VPATH 			:=	$(SRC_PATH)\
					$(SRC_PATH)system\
					$(SRC_PATH)threads\
					$(SRC_PATH)init\
					$(SRC_PATH)exec\
					$(SRC_PATH)time\
					$(INCLUDE_PATH)\
					$(SRC_PATH_BONUS)\
					$(SRC_PATH_BONUS)system\
					$(SRC_PATH_BONUS)init\

#common commands
RM 				=	rm -rf

#rules
$(OBJ_PATH)%.o: %.c
				@printf "\n$(CY)Generating object...$(RC)\n"
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@
				@printf "$(GR)Object ready!$(RC)"

$(OBJ_PATH_BONUS)%.o: %.c
				@printf "\n$(CY)Generating object...$(RC)\n"
				mkdir -p $(OBJ_PATH_BONUS)
				$(CC) $(CF) $(CFI) -c $< -o $@
				@printf "$(GR)Object ready!$(RC)"

$(NAME):		$(OBJ) $(INCLUDE)
				@printf "\n$(CY)Generating libft...$(RC)\n"
				make -C $(LIBFT_PATH) $(LIBFT)
				@printf "\n$(CY)Generating minishell executable...$(RC)\n"
				$(CC) $(CF) -I $(INCLUDE_PATH) -o $(NAME) $(OBJ) $(L_LIBFT) $(THREAD)
				@printf "$(GR)Done!$(RC)\n\n"

$(NAME_BONUS):	$(OBJ_BONUS) $(INCLUDE_BONUS)
				@printf "\n$(CY)Generating libft...$(RC)\n"
				make -C $(LIBFT_PATH) $(LIBFT)
				@printf "\n$(CY)Generating minishell executable...$(RC)\n"
				$(CC) $(CF) -I $(INCLUDE_PATH) -o $(NAME_BONUS) $(OBJ_BONUS) $(L_LIBFT) $(THREAD)
				@printf "$(GR)Done!$(RC)\n\n"

all:			$(NAME)

bonus:			$(NAME_BONUS)

re:				fclean all

clean:
				make -C $(LIBFT_PATH) clean
				$(RM) $(OBJ) $(OBJ_PATH)
				$(RM) $(OBJ_BONUS) $(OBJ_PATH_BONUS)
				@printf "$(RE)minishell objects removed!$(RC)\n\n"

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)
				$(RM) $(NAME_BONUS)
				@printf "$(RE)Executables removed!$(RC)\n\n"

.PHONY:			all clean fclean re bonus rebonus

