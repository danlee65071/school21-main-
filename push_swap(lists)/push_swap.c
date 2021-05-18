/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:46:09 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:46:10 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	if (argc < 2)
		exit (1);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		ft_parse_str(argv[1], &stack_a);
	else
		ft_parse(argc, argv, &stack_a, 0);
	ft_sort(&stack_a, &stack_b);

	//print stack_a
	t_stacks *tmp = stack_a;
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
	//

//	//print stack_b
//	tmp = stack_b;
//	while (tmp)
//	{
//		printf("%d ", tmp->value);
//		tmp = tmp->next;
//	}
//	printf("\n");
//	//
	return (0);
}

//	//print sorted array
//	int i = -1;
//	while (++i < ft_lstsize(stack_a))
//		printf("%d ", sorted_arr[i]);
//	printf("\n");
//	//

//	//print stack_a
//	tmp = stack_a;
//	while (tmp)
//	{
//		printf("%d ", tmp->value);
//		tmp = tmp->next;
//	}
//	printf("\n");
//	//
//
//	//print stack_b
//	tmp = stack_b;
//	while (tmp)
//	{
//		printf("%d ", tmp->value);
//		tmp = tmp->next;
//	}
//	printf("\n");
//	//