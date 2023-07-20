# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meliesf <meliesf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 17:52:00 by eunjiko           #+#    #+#              #
#    Updated: 2023/07/21 02:55:57 by meliesf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= minigame

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= utill.c main.c check_map.c keys.c move.c paint.c read.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c  
MLX_DIR = mlx
OBJS	= ${SRCS:.c=.o}


all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			make -C $(MLX_DIR)
			$(CC) -o $(NAME) ${OBJS} -L./mlx -lmlx -framework OpenGL -framework AppKit

clean:
			make clean -C $(MLX_DIR)/
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

norm:		
			norminette ${SRCS}
			
.PHONY:		all clean fclean re norm