/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <qtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:51:15 by qtran             #+#    #+#             */
/*   Updated: 2023/02/03 18:23:16 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	print_ll(t_node *head)
{
	t_node	*print;
	ft_printf("-----print_ll() function----\n");
	if (!head || !head->numb)
		exit(0);
	print = head;
	while (print->next != head) 
	{
		ft_printf("node: %d\n", print->numb);
		print = print->next;
	}
	ft_printf("node: %d\n", print->numb);
	//ft_printf("Test node: %d\n", print->next->numb);//geht
	//ft_printf("Test node: %d\n", print->next->next->numb);
}

void	free_ll(t_node *head)
{
	t_node	*temp;
	t_node	*tail;

	temp = head;
	tail = head->prev;
	while (temp != tail)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
	free(tail);
}

void	free_ll_prev(t_node *head)
{
	//t_node *print;
	while (head != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head->prev);
}

t_node *create_empty_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*create_node(int number)
{
	t_node	*node;

	node = create_empty_node();
	node->numb = number;
	return (node);
}

t_node	*create_double_ll(char **arr)
{
	int		i;
	t_node	*head;
	t_node	*body;
	t_node	*temp;

	i = 0;
	while (arr[i])
	{
		if (i == 0)
		{
			head = create_node(ft_atoi(arr[i]));
			temp = head;
		}
		else
		{
			body = create_node(ft_atoi(arr[i])); //ft_printf("bodypnode: %d\n", body->numb);
			temp->next = body; //ft_printf("tempnode: %d\n", temp->numb);
			body->prev = temp;
			temp = body;
		}
		i++;
	}
	body->next = head; //tail = body;//tail
	head->prev = body;
	return (head);
}

//creates an empty double ll
t_node	*create_empty_stack(int size)
{
	int	i;
	t_node	*temp;
	t_node	*body;
	t_node	*head;

	i = 0;
	while (i < size)
	{
		if (i == 0)
		{
			head = create_empty_node();
			temp = head;
		}
		else 
		{
			body = create_empty_node();
			temp->next = body;
			body->prev = temp;
			temp = body;
		}
		i++;	
	}
	body->next = head;
	head->prev = body;
	return (head);
}

void	push_from_to(t_node **from, t_node **to)
{
	t_node *newhead;
	
	newhead = *from;
	(*from)->next->prev = (*from)->prev;
	(*from)->prev->next = (*from)->next;
	
	//break and seal link

	//push head to top of stack change head of A and head of Stack
	addnode_front((*from), to);
}

void	addnode_front(t_node *new, t_node **head)
{
	t_node *tail;

	if (!new)
		return ;
	if (!(*head))
	{
		*head = new;
		(*head)->next = (*head);
		(*head)->prev = (*head);
	}
	else
	{
		tail = (*head)->prev;
		tail->next = new;
		new->prev = tail;
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}

//DARF ICH GAR NICHT
void	addnode_back(t_node **head, t_node *new)
{
	t_node *last;

	if (!*head)
	{
		*head = new;
		return;
	}
	if (!new)
		return;
	last = (*head)->prev;
	last->next = new;
	new->next = *head;
	new->prev = last;
	(*head)->prev = new;
	//last = ft_lstlast(*lst);
}

/* t_node	*ft_lstnew(int number)
{
	t_node	*first;

	first = (t_node *)malloc(sizeof(t_node));
	if (!first)
		return (NULL);
	first->numb = number;
	first->next = NULL;
	return (first);
} */
