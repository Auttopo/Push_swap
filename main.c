#include <stdio.h> //REMOVE BEFORE THE END PROJECT
#include <unistd.h> // FOR READ
#include "push_swap.h"
#include <stdlib.h>


void	show_bugs(t_stack **stack, int max)
{
	t_stack	*temp;
	int	i;

	if (*stack == NULL)
	{
		printf("no stack\n\n");
		return ;
	}

	i = 0;
	temp = (*stack)->next;
//	printf("|%d|\n", (*stack)->value);
	printf("|%d PREV %d IAM %d NEXT|  %d buk\n", (*stack)->previous->value, (*stack)->value, (*stack)->next->value, (*stack)->bucket);
	while (i < max - 1)
	{
		printf("|%d PREV %d IAM %d NEXT|  %d buk\n", temp->previous->value, temp->value, temp->next->value, temp->bucket);
//		printf("|%d|\n", temp->value);
		temp = temp->next;
		i++;
	}
	printf("\n");
}

void	show_stack(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
	{
		printf("no stack\n\n");
		return ;
	}

	temp = (*stack)->next;
	printf("|%d PREV %d IAM %d NEXT|  %d buk\n", (*stack)->previous->value, (*stack)->value, (*stack)->next->value, (*stack)->bucket);
	while (temp != *stack)
	{
		printf("|%d PREV %d IAM %d NEXT|  %d buk\n", temp->previous->value, temp->value, temp->next->value, temp->bucket);
		temp = temp->next;
	}
	printf("\n");
}
/*
static void    flag_and_lis_setup()
{

}
*/
int	main(int argc, char **argv)
{
	int		i;
	int		temp;
	int		flg;
	float	disorder;
	char	**list;
	t_flags	f;
	t_info	data;
	t_stack	*stack;
	t_stack	*pull;
	t_stack	*stk_tmp;

	list = NULL;
	i = 1;
	main_init(&data, &f, &stack, &pull);

	if (argc < 2)
		return (0);

	while (i < (argc - 1) && (i < 3) &&  argv[i][1] == '-')
	{
		temp = flag_check(f, argv[i]);
		if ((mod(data.flag) && mod(temp)) || (data.flag / 10 && temp / 10))
			return (0);
		data.flag += temp;
		i++;
	}
	if (mod(data.flag) == 4)
		data.flag -= 4;

	if (arg_uniformisation(&list, argv, argc, i) == 0)
		return (free_all(&stack, &pull, list));

	if (list == NULL)
	{
		printf("Error occured in parsing\n");
		return (0);
	}
	if (!verif_dbl(list))
	{
		printf("Error\n");
		return (0);
	}

	i = 0;
	while (list[i])
	{

		stk_tmp = add_back_nod(&stack, new_elem(ft_atoi(list[i])));
		if (stk_tmp == NULL)
			return (free_all(&stack, &pull, list));
		if (data.max < (long)stk_tmp->value)
			data.max = (long)stk_tmp->value;
		else if (data.min > (long)stk_tmp->value)
			data.min = (long)stk_tmp->value;
		i++;
	}
	data.total = i;
	data.currentot = i;
	data.buk_nbr = ((float)ft_sqrt(data.total)); //* (float)0.6);
	if (data.buk_nbr < 1)
		data.buk_nbr = 1;
	disorder = compute_disorder(stack);

//	show_stack(&stack);
//	show_stack(&pull);


	if (mod(data.flag) == 1 || (disorder < (float)0.2 && mod(data.flag) == 0)) // Value data.total just to test, we have to do less than 25 op for 5 4 3 2 1
	{
		selection(&data, &stack, &pull);
		bench_mod(data, disorder, 1);
	}
	else if (mod(data.flag) == 2 || (disorder < (float)0.5 && mod(data.flag) == 0))
	{
		buckets(&data, &stack, &pull);
		bench_mod(data, disorder, 2);
	}
	else if (mod(data.flag) == 3 || (disorder >= (float)0.5 && mod(data.flag) == 0))
	{
		if (data.total < 50)
			radix(&data, &stack, &pull, data.total, 10, radix_move_10);
		else
			radix(&data, &stack, &pull, data.total, 2, radix_move);
		bench_mod(data, disorder, 3);
	}

//	printf("\n");
//	show_stack(&stack);
//	show_stack(&pull);

	free_all(&stack, &pull, list);
}
