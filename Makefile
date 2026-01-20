CFLAGS= cc -Wall -Wextra -Werror
OBJ=	ft_printf.o ft_printf_cases.o ft_printf_hex.o \
		main.o utils.o parser.o stack.o parser_utils.o display.o rules1.o rules2.o disordermetric.o \
		selection.o bubble.o \
		buckets.o buckets_utils.o \
		radix.o radix_utils.o

OBJBONUS=	checker_bonus.o checker_utils_bonus.o checker_utils2_bonus.o checker_rules_bonus.o \
			parser_bonus.o parser_utils_bonus.o stack_bonus.o utils_bonus.o \
			disordermetric_bonus.o display_bonus.o ft_split_bonus.o ft_bzero_bonus.o \
			ft_printf_bonus.o ft_printf_cases_bonus.o ft_printf_hex_bonus.o \
			get_next_line_bonus.o get_next_line_utils_bonus.o

NAMEBONUS= checker
NAME= push_swap


all : $(NAME)
bonus : $(NAMEBONUS)


%.o : %.c push_swap.h ft_printf.h
	$(CFLAGS) -c $< -o $@

%_bonus.o : %_bonus.c
	$(CFLAGS) -c $< -o $@


$(NAME) : $(OBJ)
	$(CFLAGS) $(OBJ) -o $(NAME)

$(NAMEBONUS) : $(OBJBONUS)
	$(CFLAGS) $(OBJBONUS) -o $(NAMEBONUS)



clean :
	$(RM) $(OBJ)
cleanbonus :
	$(RM) $(OBJBONUS)


fclean :
	$(RM) $(NAME) $(OBJ) 
fcleanbonus :
	$(RM) $(NAMEBONUS) $(OBJBONUS)


re : fclean all

rebonus : fcleanbonus bonus

.PHONY : all clean fclean re
