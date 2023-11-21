# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:57:00 by gle-roux          #+#    #+#              #
#    Updated: 2023/07/31 14:04:13 by gle-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	= 	-Wall -Wextra -Werror

# Remove and Archives
RM		=	rm -rf
ARCH	=	ar rcs	

# Dir and file names
NAME			=	libft.a

SRCS_DIR	=	./src/
SRCS_LIST	=	ft_atoi.c \
				ft_atol.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_char_tab_len.c \
				ft_free_tab_char.c \
				ft_free_tab_int.c \
				ft_freenull.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_iswhitespace.c \
				ft_sort_params.c \
				ft_swap_bin.c \
				ft_itoa.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_split.c \
				ft_str_isdigit.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				get_next_line.c \
				get_next_line_utils.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR	=	./obj/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

HEADER_DIR	=	./include/
HEADER_LIST	=	libft.h
HEADER	 	=	$(addprefix $(HEADER_DIR), $(HEADER_LIST))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

# Colors settings
R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)

# Print settings
ERASE_LINE	=	\033[2K\r

# Creation of the executable
all: dir $(NAME)

# Compile library
$(NAME): $(OBJS)
	@$(ARCH) $(NAME) $(OBJS)
	@echo "$(ERASE_LINE)$W----------------------- $Ylibft $Wis $Gdone ✅$W ----------------------\n"

# Create all files .o (object) from files .c (source code)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@printf "$(ERASE_LINE) $YCompiling : $W$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

#Create directory for *.o files
dir:
	@mkdir -p $(OBJS_DIR)

# Removes objects
clean:
	@$(RM) $(OBJS_DIR)
	@echo "\n$W--------------- $(NAME) : $(OBJS_DIR) was $Rdeleted ❌$W----------------\n"

# Removes all objects and executables
fclean: clean
	@$(RM) $(NAME)
	@echo "$W-------- All exec. and archives successfully $Rdeleted ❌$W--------"

# Removes objects and executables and remake
re: fclean
	@$(MAKE) all

# Avoids file-target name conflicts
.PHONY: all dir clean fclean re