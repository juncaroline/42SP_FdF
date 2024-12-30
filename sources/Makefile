# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 12:56:24 by cabo-ram          #+#    #+#              #
#    Updated: 2024/12/30 18:18:53 by cabo-ram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ../libraries/MLX42
LIBFT	:= ../libraries/libft
GNL		:= ../libraries/get_next_line

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include -I $(GNL)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a $(GNL)/get_next_line.a -ldl -lglfw -pthread -lm
SRCS	:= complement.c init.c line.c line_utils.c main.c \
			parse.c parse_utils.c render.c render_utils.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx libft gnl $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

gnl:
	@make -C $(GNL)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean
	@make -C $(GNL) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(GNL) fclean

re: clean all

.PHONY: all clean fclean re libmlx libft gnl