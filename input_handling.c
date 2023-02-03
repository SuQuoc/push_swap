/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <qtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:56:36 by qtran             #+#    #+#             */
/*   Updated: 2023/02/03 17:57:55 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == ' ')
			return (1);
		if (str[i] != '-' && str[i] != ' ' && !('0' <= str[i] && str[i] <= '9'))
			return (1);
		if (str[i] == '-' && !('0' <= str[i + 1] && str[i + 1] <= '9'))
			return (1);
		if (i > 0 && str[i] == '-' && str[i - 1] != ' ')
			return (1);
		if (str[i] == ' ' && str[i + 1] != '-' && !('0' <= str[i + 1] && str[i
				+ 1] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

char *create_str(char **av)
{
	int i;
	char *str;
	char *temp;
    
	i = 1;
	str = ft_strjoin(av[i], "");;
	while (av[i])
	{
		printf("av: %s\n", av[i]);
		if (av[i + 1] != NULL)
		{
			temp = ft_strjoin(str, " ");
            free(str);
			str = ft_strjoin(temp, av[i + 1]);
            free(temp);
		}
		i++;
	}
	return (str);
}

int	check_int_range(char **arr)
{
	int i;
	int len;

	i = 0;
	while (arr[i])
	{
		//printf("Str[%d]: %s\n", i,  arr[i]);
		len = ft_strlen(arr[i]);
		if (len >= 11 && arr[i][0] == '-' && ft_strncmp(arr[i], INT_MIN , len) > 0)
		{
			ft_printf("Error, you are under int min range!\n"); //
			return (1);
		}
		if (len >= 10 && ft_strncmp(arr[i], INT_MAX , len) > 0)
		{
			ft_printf("Error, you are over int max range!\n"); //
			return (1);
		}
		//ft_printf("cmp: %d\n", ft_strncmp(arr[i], INT_MAX ,ft_strlen(arr[i])));
		i++;
	}
    return (0);
}

int check_arg_count(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	if (i < 2)
	{
		ft_printf("Too few args\n");//
		return (1);
	}
	return (0);
}

int	check_double(char **arr)
{
	int i;
	int j;
	int len1;
	int len2;

	i = 0;
	while (arr[i])
	{
		//printf("Str[%d]: %s\n", i,  arr[i]);
		len1 = ft_strlen(arr[i]);
		j = i + 1;
		while (arr[j])
		{
			len2 = ft_strlen(arr[j]);
			if (len1 == len2 && ft_strncmp(arr[i], arr[j] , len1) == 0)
			{
				ft_printf("Error, you have doubles!\n");//
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int check_if_sorted(char **arr)
{
	int i;
	int len1;
	int	len2;

	i = 0;
	while (arr[i])
	{
		len1 = ft_strlen(arr[i]);
		len2 = ft_strlen(arr[i + 1]);
		if (arr[i + 1])
		{
			if (len1 > len2 || (len1 == len2 && ft_strncmp(arr[i], arr[i + 1], len1) > 0))
				i++;
			else 
			{
				ft_printf("Bruuh, its already sorted\n");//
				return (0);
			}
		}
	}
	return (0);
}


void	free_2d_arr(char **arr)
{
    int i;

    i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
    free(arr[i]);
	free(arr);
}