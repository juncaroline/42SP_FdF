# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 12:56:24 by cabo-ram          #+#    #+#              #
#    Updated: 2025/01/08 15:35:18 by cabo-ram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf
NAME_BONUS	:= fdf_bonus
CFLAGS	:= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ../libraries/MLX42
LIBFT	:= ../libraries/libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
SRCS	:= $(addprefix mandatory/,color.c color_utils.c complement.c init.c \
			line.c line_utils.c main.c parse.c parse_utils.c render.c \
			render_utils.c)
SRCS_BONUS :=$(addprefix bonus/,color_bonus.c color_utils_bonus.c \
			complement_bonus.c init_bonus.c keyboard_command_bonus.c \
			keyboard_command_utils_bonus.c line_bonus.c line_utils_bonus.c \
			main_bonus.c parse_bonus.c parse_utils_bonus.c render_bonus.c \
			render_utils_bonus.c rotation_bonus.c) 
OBJS	:= ${SRCS:.c=.o}
OBJS_BONUS := ${SRCS_BONUS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

bonus: libmlx libft $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)
	
clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT) fclean

re: clean all

.PHONY: all clean fclean re libmlx libft