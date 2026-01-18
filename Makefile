CFLAGS= cc -Wall -Wextra -Werror
OBJ=	ft_printf.o ft_printf_cases.o ft_printf_hex.o \
		main.o utils.o parser.o stack.o parser_utils.o display.o rules1.o rules2.o disordermetric.o \
		selection.o bubble.o \
		buckets.o buckets_utils.o \
		radix.o radix_utils.o
NAME= push_swap

all : $(NAME)

%.o : %.c push_swap.h
	$(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CFLAGS) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(NAME) $(OBJ)

re : fclean all

.PHONY : all clean fclean re
