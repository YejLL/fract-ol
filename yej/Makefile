# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejlee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 11:52:10 by yejlee            #+#    #+#              #
#    Updated: 2022/04/12 18:27:23 by yejlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	= \033[32m
BLUE	= \033[34m
YELLOW	= \033[0;33m
VIOLET	= \033[1;35m
WHITE	= \033[1;37m
RESET	= \033[0m

NAME			=	fractol
SRCS_DIR		=	./src/
INCLUDES		=	./inc/
BONUS_DIR		=	./bonus/
SRCS_F			=	hooks.c init.c fractals.c main.c utils.c
SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))
OBJS			=	$(SRCS:.c=.o)
CC				=	cc
CC_FLAGS		= 	-Wall -Wextra -Werror -O3
.c.o:
				@$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o) -I ./inc -I ./minilibx
$(NAME):		$(OBJS)
				@make -sC ./minilibx all
				@$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME) -L ./minilibx -lmlx -framework OpenGL -framework AppKit -lz
				@echo "$(VIOLET)Fractol is successfully compiled!$(RESET)"
				@echo "$(YELLOW)You can run the program with arguments of Mandelbrot, Julia or Burningship.$(RESET)"
				@echo "$(GREEN)(Be sure to start with capital letters, and don't forget to give coordinates for Julia!)$(RESET)"
all:			$(NAME)

bonus:			
				cd $(BONUS_DIR) && make all

clean:
				@make -sC ./minilibx clean
				@rm -f $(OBJS)
fclean:			clean
				@rm -f $(NAME)
				cd $(BONUS_DIR) && make fclean
re:				fclean all

.PHONY:			all clean fclean re bonus
