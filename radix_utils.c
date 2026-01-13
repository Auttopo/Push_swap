
#include "push_swap.h"

void    min_indexing(int total, t_stack *local, int x)
{
	t_stack	*temp;
        long    comp;
        int     i;
	int	pos;

        comp = 3000000000;
        i = 0;
        while (i < total)
        {
                if (((long)local->value < comp) && (local->index == -1))
                {
                        temp = local;
                        comp = (long)local->value;
                }
                local = local->next;
                i++;
        }

	temp->index = x;
}

void	init_index(t_stack *stack, int size)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		min_indexing(size, stack, i);
		i++;
	}
}
