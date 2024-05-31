# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: capapes <capapes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 18:47:51 by capapes           #+#    #+#              #
#    Updated: 2024/05/16 12:17:05 by capapes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c  \
ft_isalpha.c  ft_isalnum.c  ft_isascii.c ft_isempty.c ft_isdigit.c ft_isprint.c  ft_issign.c  ft_itoa.c\
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
ft_split.c ft_strchr.c ft_strdup.c  ft_striteri.c ft_strjoin.c  ft_strmapi.c ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c  ft_strrchr.c  \
ft_strtrim.c ft_substr.c ft_toupper.c ft_tolower.c \
ft_lstadd_back.c ft_lstadd_front.c  ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstlast.c  ft_lstmap.c ft_lstnew.c ft_lstsize.c 
BUILD_DIR = ./build
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)
DPS := $(SRC:%.c=$(BUILD_DIR)/%.d)
PREQ = Makefile


#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Target
all: ${NAME}

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)📚completed		libft.a$(DEF_COLOR)"

$(BUILD_DIR)/%.o: %.c $(PREQ) | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c -MMD -o $@ $<
	@echo "$(GRAY)⏳compiling		$<$(DEF_COLOR)"

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(RED)🧹clean		libft$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)

re: fclean all 

-include $(DPS)

.PHONY: all clean fclean re
