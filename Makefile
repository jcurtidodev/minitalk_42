# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 18:49:32 by jcurtido          #+#    #+#              #
#    Updated: 2025/02/10 17:00:19 by jcurtido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre
NAME_CLIENT = client
NAME_SERVER = server

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror 

# Directorios
SRCS_DIR = .
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Archivos fuente
SRCS_CLIENT = client.c
SRCS_SERVER = server.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

# Reglas
all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

$(OBJS_CLIENT): $(SRCS_CLIENT)
$(OBJS_SERVER): $(SRCS_SERVER)

.PHONY: all clean fclean re
