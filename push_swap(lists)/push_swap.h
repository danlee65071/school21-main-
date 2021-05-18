/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:46:19 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:46:20 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stacks
{
	int				value;
	int				index_in_sort_arr;
	int				was_in_b;
	struct s_stacks	*next;
	struct s_stacks	*prev;
}	t_stacks;

t_stacks	*ft_lstlast(t_stacks *lst);
void		ft_lstadd_back(t_stacks **lst, t_stacks *new);
int			ft_atoi(const char *str);
t_stacks	*ft_lstnew(int value, int ind_in_sort_arr, int was_in_b);
void		ft_parse(int argc, char **argv, t_stacks **stack_a,
			   			int is_str_parse);
int			ft_error(void);
size_t		ft_strlen(const char *s);
int			ft_is_el_in_list(t_stacks *stack, int value);
char		**ft_split(char const *s, char c);
void		ft_lstadd_front(t_stacks **lst, t_stacks *new);
void		ft_parse_str(char *str, t_stacks **stack_a);
void		ft_sa(t_stacks	**stack_a, int is_ss);
void		ft_sb(t_stacks	**stack_b, int is_ss);
void		ft_ss(t_stacks **stack_a, t_stacks **stack_b);
void		ft_pa(t_stacks **stack_a, t_stacks **stack_b);
void		ft_pb(t_stacks **stack_a, t_stacks **stack_b);
void		ft_ra(t_stacks **stack_a, int is_rr);
void		ft_rb(t_stacks **stack_b, int is_rr);
void		ft_rr(t_stacks **stack_a, t_stacks **stack_b);
void		ft_rra(t_stacks **stack_a, int is_rrr);
void		ft_rrb(t_stacks **stack_b, int is_rrr);
void		ft_rrr(t_stacks **stack_a, t_stacks **stack_b);
void		ft_sort_arr(int **arr, int len_arr);
int			ft_lstsize(t_stacks *stack);
void		ft_init_arr(int **arr, int len_arr, t_stacks *stacks);
void		ft_set_indexes_in_sort_arr(t_stacks **stack, int *sorted_arr);
int			ft_find_median(t_stacks *stack);
void		ft_sort(t_stacks **stack_a, t_stacks **stack_b);
int			ft_find_place_value(t_stacks *stack, int value);
void		ft_to_top_in_stack(t_stacks **stack, int value_to_top,
						 		int is_stack_a);
void		ft_transfer_from_a_to_b(t_stacks **stack_a, t_stacks **stack_b);
void		ft_is_in_place(t_stacks **stack, int *min_not_sorted_el, int
							*sorted_arr);
void		ft_transfer_from_b_to_a(t_stacks **stack_a, t_stacks **stack_b, int
								*min_not_sorted_el, int *sorted_arr);
t_stacks	*ft_part_of_the_stack(t_stacks **stack);
void		ft_lstdel(t_stacks **stack);
t_stacks	*ft_top_el_wich_was_in_b(t_stacks **stack);

#endif
