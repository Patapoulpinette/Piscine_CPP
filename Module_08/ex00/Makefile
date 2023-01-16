# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 11:20:24 by dbouron           #+#    #+#              #
#    Updated: 2023/01/10 13:17:57 by dbouron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind

# **************************************************************************** #
#                               FILES and PATHS                                #
# **************************************************************************** #

SRCS =	$(shell find . -name "*.cpp")
HEADFILE = $(shell find . -name "*.hpp")

CPPFLAGS = -Wall -Wextra -Werror
CPPFLAGS += -std=c++98
#CPPFLAGS += -fsanitize=address -g3

# **************************************************************************** #
#                                    COLORS                                    #
# **************************************************************************** #

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m

# **************************************************************************** #
#                              COMMANDS and RULES                              #
# **************************************************************************** #

.SILENT:

.DEFAULT_GOAL = all

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o: %.cpp $(HEADFILE) Makefile
	c++ $(CPPFLAGS) -o $@ -c $<
	@printf "\r$(LIGHT_GRAY)Loading...$(NO_COLOR)"

$(NAME) : $(OBJS) $(HEADFILE)
	c++ $(CPPFLAGS) -o $(NAME) $(SRCS)
	@printf "\r$(LIGHT_GREEN)➞$(NO_COLOR) Compiled $(LIGHT_GREEN)✔$(NO_COLOR)\n"

clean :
	rm -rf $(OBJS)
	@printf "\r$(LIGHT_BLUE)➞$(NO_COLOR) Cleaned $(LIGHT_BLUE)✔$(NO_COLOR)\n"

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re