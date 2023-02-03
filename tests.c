/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <qtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:50:37 by qtran             #+#    #+#             */
/*   Updated: 2023/02/03 18:25:22 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>



//// TEST SPLIT from github also creates same errors

int	main(int ac, char **av)
{
	char **arr;
	char *str;
	if (ac == 1)
	{
		ft_printf("Too few args\n"); //Error\n
		return (0);
	}
	str = create_str(av);
	if (check_if_numeric(str) == 1)
	{
		ft_printf("Input not valid\n"); //Error\n
		return 0;
	}
	ft_printf("One whole string: %s\n", str);//
	arr = ft_split(str, ' ');
	free(str);
	if (check_arg_count(arr) + check_int_range(arr) + check_double(arr) + check_if_sorted(arr) > 0)
	{
		ft_printf("Error\n");
		free_2d_arr(arr);
		return (0);
	}
	
	t_data data;
	data.list_size = count_stack_contents(arr);
	ft_printf("Stack size: %d\n", data.list_size);

	t_node *head_a;
	head_a = create_double_ll(arr);
	int m = find_median(data.list_size, head_a);
	ft_printf("MMMMMM: %d\n", m);

	print_ll(head_a);
	free_ll(head_a);
	
	ft_printf("---------STACK B--------\n");
	t_node *head_b;
	
	push_from_to(&head_a, &head_b);
	push_from_to(&head_a, &head_b);
	print_ll(head_b);
	free_ll(head_b);
	//free(head);
	
	free_2d_arr(arr);
	return (0);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void print_int_arr(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("arr[%d]: %d\n", i, arr[i]);
		i++;
	}
}

void bubblesort(int *arr, int size)
{
	int i;
	int j;
	int swap;
	
	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int find_median(int size, t_node *head)
{
	int arr[size];
	int	i;
	t_node	*temp;

	temp = head;
	i = 0;
	while (i < size)
	{
		arr[i] = temp->numb;
		temp = temp->next;
		i++;
	}
	print_int_arr(arr, size);
	bubblesort(arr, size);
	ft_printf("Sorted:\n");
	print_int_arr(arr, size);
	return (arr[size / 2 - 1]);
}




int	count_stack_contents(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}
/* long long int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
} */
