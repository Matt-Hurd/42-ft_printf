# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/25 19:00:08 by mhurd             #+#    #+#              #
#    Updated: 2016/11/20 03:37:56 by mhurd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_INCLUDE_PATH += includes/ libft

CFLAGS += -Wall -Wextra -Werror
CFLAGS += $(foreach d, $(C_INCLUDE_PATH), -I$d)

SRCS = src/ft_printf.c \
	   src/helpers/flag_finder.c \
	   src/helpers/handle_padding.c \
	   src/helpers/handle_precision.c \
	   src/conversions/ft_conv_s.c \
	   src/conversions/ft_conv_c.c \
	   src/conversions/ft_conv_unimp.c \

LIBFT_FUNS =	memalloc \
				putstr \
				strchr \
				strdup \
				strncpy \
				strnew \
				bzero \
				putstr_fd \
				putstr_fd \
				strlen \
				memset \
				strcpy \
				atoi \
				isdigit \
				isspace \
				strnjoin \
				memcpy

CFLAGS += $(foreach fun,$(LIBFT_FUNS),-Dft_$(fun)=ft_printf_libft_$(fun))

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))
OBJS += $(foreach fun,$(LIBFT_FUNS),obj/libft/ft_$(fun).o)

CP = cp

RM = rm -f

all: $(NAME)

$(OBJS): | obj

obj:
	@mkdir -p $@
	@mkdir -p $@/handlers
	@mkdir -p $@/utils
	@mkdir -p $@/libft
	@mkdir -p $@/helpers
	@mkdir -p $@/conversions

obj/%.o: src/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

obj/libft/%.o: libft/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $^

clean:
	$(RM) $(OBJS)

test: $(NAME)
	$(CC) -o $@ -I includes main.c -L. -lftprintf

fclean: clean
	$(RM) $(NAME)
	$(RM) -rf obj

re: fclean all

.PHONY: all clean fclean re
