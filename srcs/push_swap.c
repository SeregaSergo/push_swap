/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:04:59 by bswag             #+#    #+#             */
/*   Updated: 2021/04/30 20:29:24 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <fcntl.h>

int	do_oper_print(char *oper, t_list **a, t_list **b, int n)
{
	while (n > 0)
	{
		do_operation(oper, a, b);
		ft_putendl_fd(oper, 1);
		n--;
	}
	return (0);
}

void	check_swaps(t_list **a, t_list **b)
{
	int	change;
	
	change = 0;
	if (*a && (*a)->next)
	{
		if (*((long long int *)(*a)->content) > *((long long int *)(*a)->next->content))
			change = 1;
	}
	if (*b && (*b)->next)
	{
		if (*((long long int *)(*b)->content) < *((long long int *)(*b)->next->content))
			change += 10;
	}
	if (change == 11)
		do_oper_print("ss", a, b, 1);
	if (change == 10)
		do_oper_print("sb", a, b, 1);
	if (change == 1)
		do_oper_print("sa", a, b, 1);
}

int		what_to_rotate(t_list *a, t_list *b, long long int mod_a, long long int mod_b)
{
	int	res;
	
	res = 0;
	if (a && *((long long int *)a->content) > mod_a)
		res += 1;
	if (b && *((long long int *)b->content) < mod_b)
		res += 10;
	return (res);
}

int		what_to_reverse(t_list *a, t_list *b, long long int mod_a, long long int mod_b)
{
	int	res;
	
	res = 0;
	if (a && *((long long int *)ft_lstlast(a)->content) < mod_a)
		res += 1;
	if (b && *((long long int *)ft_lstlast(b)->content) > mod_b)
		res += 10;
	return (res);
}

void merge(long long int A[],int p,int q,int r)
{
    int n1=q-p+1,n2=r-q;
    long long int L[n1+1],R[n2+1],i,j,k;
    L[n1]=LLONG_MAX;
    R[n2]=LLONG_MAX;
	
    for (i=0;i<n1;i++)
        L[i]=A[p+i];

    for (j=0;j<n2;j++)
        R[j]=A[q+j+1];

    i=0;j=0;

    for (k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
}

void part(long long int A[],int p,int r)
{
    if (p<r)
    {
        int q=(p+r)/2;
        part(A,p,q);
        part(A,q+1,r);
        merge(A,p,q,r);
    }
}

long long int	find_middle_int(t_list *stack)
{
	int				len;
	long long int	*ar;
	int				i;
	long long int	res;
	
	i = 0;
	len = ft_lstsize(stack);
	if (!(ar = (long long int *)malloc(sizeof(long long int) * len)))
		error_msg();
	while (stack)
	{
		ar[i] = *((long long int *)stack->content);
		stack = stack->next;
		i++;
	}
	part(ar, 0, len -1);
	res = ar[len / 2];
	free(ar);
	return (res);
}

int	check_reverse_rotate(t_list **a, t_list **b)
{
	long long int	mod_a;
	long long int	mod_b;
	int	rotate;
	int	reverse;
	
	mod_a = find_middle_int(*a);
	mod_b = find_middle_int(*b);
	rotate = what_to_rotate(*a, *b, mod_a, mod_b);
	reverse = what_to_reverse(*a, *b, mod_a, mod_b);
	if (reverse == 11)
		return (do_oper_print("rrr", a, b, 1));
	if (rotate == 11)
		return (do_oper_print("rr", a, b, 1));
	if (rotate == 10)
		return (do_oper_print("rb", a, b, 1));
	if (rotate == 1)
		return (do_oper_print("ra", a, b, 1));
	if (reverse == 10)
		return (do_oper_print("rrb", a, b, 1));
	if (reverse == 1)
		return (do_oper_print("rra", a, b, 1));
	return (0);
}

void	scroll_stack(t_list **a, t_list **b)
{
	t_mml	mml;
	
	max_min_elem_list(*a, &mml);
	// printf("min_val = %lli, min_pos = %i\n", mml.min_val, mml.min_pos);
	if (mml.min_pos < (ft_lstsize(*a) / 2))
		do_oper_print("ra", a, b, mml.min_pos);
	else
		do_oper_print("rra", a, b, ft_lstsize(*a) - mml.min_pos);
	// print_stacks(*a, *b);
}

void	sort_stack_iter(t_list **a, t_list **b)
{
	int	len;
	long long int	mid;
	
	mid = find_middle_int(*a);
	len = ft_lstsize(*a);
	while (len-- != 1 && check_result(*a))
	{
		check_reverse_rotate(a, b);
		check_result(*a) ? check_swaps(a, b) : 0;
		check_result(*a) ? do_oper_print("pb", a, b, 1) : 0;
		// print_stacks(*a, *b);
	}
	len = ft_lstsize(*b);
	while (len-- != 0)
	{
		prepare_push_back(a, b);
		do_oper_print("pa", a, b, 1);
		// print_stacks(*a, *b);
	}
	scroll_stack(a, b);
}

int		main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	
	b = NULL;
	if (argc < 2)
		error_msg();
	if (fill_stack_a(&argv[1], &a))
		error_msg();
	// print_stacks(a, b);
	sort_stack_iter(&a, &b);
	return (0);
}