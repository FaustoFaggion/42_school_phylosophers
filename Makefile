# -*- Makefile -*-

#	@	target name
#	^	all dependencies
#	<	first dependencie
#	-c	create a file.o
#	-o	place the output in a file 'file.'

#target:	depenencies
#	action

NAME			= 	philo

#compilation
CC 				=	gcc
CF 				=	-Wall -Wextra -Werror
CFI 			=	-I $(INCLUDE_PATH)
THREAD			=	-lpthread

SRC_PATH 		=	./src/
OBJ_PATH		=	./obj/
INCLUDE_PATH 	=	./include/

L_LIBFT			=	-L $(LIBFT_PATH) -lft

INCLUDE			=	philosophers.h

SRC				=	main.c\
					system_calloc.c\
					system_atoi.c\
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
					system_calloc_bonus.c\
					system_atoi_bonus.c\
					init_process_bonus.c\
					clean_bonus.c\
					time_bonus.c\
					setup_table_bonus.c\
					create_philo_bonus.c\
					lunch_bonus.c\
					lunch_actions_bonus.c\
					#control_lunch.c\
					wait_and_destroy.c\
					

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
					$(SRC_PATH_BONUS)process\
					$(SRC_PATH_BONUS)init\
					$(SRC_PATH_BONUS)exec\
					$(SRC_PATH_BONUS)time\

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
				@printf "\n$(CY)Generating philosopher executable...$(RC)\n"
				$(CC) $(CF) -I $(INCLUDE_PATH) -o $(NAME) $(OBJ) $(THREAD)
				@printf "$(GR)Done!$(RC)\n\n"

$(NAME_BONUS):	$(OBJ_BONUS) $(INCLUDE_BONUS)
				@printf "\n$(CY)Generating libft...$(RC)\n"
				@printf "\n$(CY)Generating philosopher executable...$(RC)\n"
				$(CC) $(CF) -I $(INCLUDE_PATH) -o $(NAME_BONUS) $(OBJ_BONUS) $(THREAD)
				@printf "$(GR)Done!$(RC)\n\n"

all:			$(NAME)

bonus:			$(NAME_BONUS)

re:				fclean all

clean:
				$(RM) $(OBJ) $(OBJ_PATH)
				$(RM) $(OBJ_BONUS) $(OBJ_PATH_BONUS)
				@printf "$(RE)minishell objects removed!$(RC)\n\n"

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(NAME_BONUS)
				@printf "$(RE)Executables removed!$(RC)\n\n"

.PHONY:			all clean fclean re bonus rebonus

