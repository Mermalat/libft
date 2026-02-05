# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merma <merma@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 21:32:13 by merma             #+#    #+#              #
#    Updated: 2026/02/05 02:46:59 by merma            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRCS =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
        ft_toupper.c ft_tolower.c ft_memset.c ft_memcpy.c ft_memmove.c \
        ft_memchr.c ft_memcmp.c ft_bzero.c ft_strlen.c ft_strlcpy.c \
        ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
        ft_strdup.c ft_atoi.c ft_calloc.c ft_substr.c ft_strjoin.c \
        ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
        ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
        ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
        ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Düzeltilmiş Run Komutu: $(NAME) ekledik
run: $(NAME)
	$(CC) $(FLAGS) ft_main.c $(NAME) -o test
	@echo "\n --- Running Test --- \n"
	@./test
	@echo "\n --- Test Finished, Test file is getting deleted --- \n"
	@rm -f test

.PHONY: all clean fclean re run