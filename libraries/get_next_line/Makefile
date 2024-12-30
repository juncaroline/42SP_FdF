# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 18:16:02 by cabo-ram          #+#    #+#              #
#    Updated: 2024/12/30 18:18:24 by cabo-ram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c \

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c \

OBJS = $(SRC:.c=.o)
OBJSBONUS = $(SRC_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)

bonus: $(OBJS) $(OBJSBONUS)
	@make OBJS="$(OBJS) $(OBJSBONUS)" --no-print-directory 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re