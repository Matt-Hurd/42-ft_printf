# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/25 19:00:08 by mhurd             #+#    #+#              #
#    Updated: 2016/12/30 11:58:38 by mhurd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
FLAGS =	-Wall -Wextra -Werror
CC = 	gcc
ODIR =	bin/
IDIR =	includes/
SRC =
OBJ =	$(SRC:.c=.o)
EXT =	$(IDIR)ft_printf.h

EXT +=	Makefile
SRC =	src/ft_printf.c \
		src/helpers/flag_finder.c \
		src/helpers/handle_padding.c \
		src/helpers/handle_precision.c \
		src/helpers/num_to_string.c \
		src/helpers/wchar_to_str.c \
		src/helpers/num_helpers.c \
		src/conversions/ft_conv_s.c \
		src/conversions/ft_conv_c.c \
		src/conversions/ft_conv_nums.c \
		src/conversions/ft_conv_unimp.c \
		src/conversions/ft_conv_percent.c \
		src/conversions/ft_conv_n.c \
		src/libft/ft_islower.c \
		src/libft/ft_isupper.c \
		src/libft/ft_isalpha.c \
		src/libft/ft_isdigit.c \
		src/libft/ft_isalnum.c \
		src/libft/ft_isascii.c \
		src/libft/ft_isprint.c \
		src/libft/ft_toupper.c \
		src/libft/ft_tolower.c \
		src/libft/ft_isspace.c \
		src/libft/ft_memset.c \
		src/libft/ft_bzero.c \
		src/libft/ft_memcpy.c \
		src/libft/ft_memccpy.c \
		src/libft/ft_memmove.c \
		src/libft/ft_memchr.c \
		src/libft/ft_memcmp.c \
		src/libft/ft_memalloc.c \
		src/libft/ft_memdel.c \
		src/libft/ft_realloc.c \
		src/libft/ft_putchar.c \
		src/libft/ft_putchar_fd.c \
		src/libft/ft_putendl.c \
		src/libft/ft_putendl_fd.c \
		src/libft/ft_putnbr.c \
		src/libft/ft_putnbr_fd.c \
		src/libft/ft_putstr.c \
		src/libft/ft_putstr_fd.c \
		src/libft/ft_print_memory.c \
		src/libft/ft_strlen.c \
		src/libft/ft_strdup.c \
		src/libft/ft_strcpy.c \
		src/libft/ft_strncpy.c \
		src/libft/ft_strcat.c \
		src/libft/ft_strncat.c \
		src/libft/ft_strlcat.c \
		src/libft/ft_strchr.c \
		src/libft/ft_strrchr.c \
		src/libft/ft_strstr.c \
		src/libft/ft_strnstr.c \
		src/libft/ft_strcmp.c \
		src/libft/ft_strncmp.c \
		src/libft/ft_strrev.c \
		src/libft/ft_strnew.c \
		src/libft/ft_strdel.c \
		src/libft/ft_strclr.c \
		src/libft/ft_striter.c \
		src/libft/ft_striteri.c \
		src/libft/ft_strmap.c \
		src/libft/ft_strmapi.c \
		src/libft/ft_strequ.c \
		src/libft/ft_strnequ.c \
		src/libft/ft_strsub.c \
		src/libft/ft_strjoin.c \
		src/libft/ft_strtrim.c \
		src/libft/ft_strsplit.c \
		src/libft/ft_strnjoin.c \
		src/libft/ft_strnjoinf.c \
		src/libft/ft_strcjoin.c \
		src/libft/ft_printjoin.c \
		src/libft/ft_count_words.c \
		src/libft/ft_atoi.c \
		src/libft/ft_itoa.c \
		src/libft/ft_itoa_base.c \
		src/libft/ft_lstnew.c \
		src/libft/ft_lstdelone.c \
		src/libft/ft_lstdel.c \
		src/libft/ft_lstadd.c \
		src/libft/ft_lstiter.c \
		src/libft/ft_lstmap.c \
		src/libft/ft_lstmap.c \
		src/libft/ft_lstdelcont.c \
		src/libft/ft_lst_add_back.c \
		src/libft/ft_strcatf.c \
		src/libft/ft_strjoinf.c \
		src/libft/ft_gnl.c

O =		$(addprefix $(ODIR), $(OBJ))

ifdef ALLOCWRAP
	LDFLAGS += $(HOME)/lib/alloc_wrap.c -ldl
endif

all: $(NAME)

love: all

norm:
	norminette $(S)

$(NAME): $(O) $(EXT)
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

$(ODIR)%.o: %.c $(EXT)
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -c -I includes $< -o $@

$(O): | ./bin

./bin:
	@mkdir $(ODIR)
	@mkdir $(ODIR)src/
	@mkdir $(ODIR)src/conversions/
	@mkdir $(ODIR)src/helpers/
	@mkdir $(ODIR)src/libft/

test: $(NAME)
	$(CC) $(LDFLAGS) -o $@ -I includes main.c -L. -lftprintf

clean:
	@echo "-> Cleaning libft object files..."
	@rm -rf bin/
	@make -C libft/ clean

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re norm
