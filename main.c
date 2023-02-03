/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <qtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:22:10 by qtran             #+#    #+#             */
/*   Updated: 2023/01/31 15:48:22 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "push_swap.h"

char *create_str(char **av)
{
	int i;
	char *str;
	
	i = 0;
	while (av[i])
	{
		if (av[i + 1] != NULL)
		{
			str = ft_strjoin(av[i], " ");
			str = ft_strjoin(str, av[i + 1]);
		}
		i++;
	}
	return (str);
}

int	main(int ac, char **av)
{
	char **arr;
	char *str;
	if (ac < 2)
	{
		perror("Too many args");
		return (0);
	}
	str = create_str(av);
	arr = ft_split(str, ' ');

	int i = 0;
	while (arr[i])
	{
		printf("Str: %s\n", arr[i]);
		i++;
	}
    return 0;
}

/* 
   int *arr;
    arr = malloc(sizeof(int) * (ac - 1));
    int i;
    i = 1;
    while (av[])
    check for doubles --> in int arr reinhauen und 
check_if_all_int()



check_doubles()
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (arr[i])
    {
        while(arr[j])
        {
            if (arr[i] == arr[j])
                return (ERROR);
            j++;
        }
        i++;
        j = i + 1;
    }   
} */