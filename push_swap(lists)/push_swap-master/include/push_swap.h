/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:27:27 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 18:43:30 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define WIDTH 1920
# define HEIGHT 1080

# include "ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>

typedef	struct			s_status
{
	int					next;
	int					mid;
	int					max;
	int					moving;
	int					last;
}						t_status;
typedef struct			s_stack
{
	int					num;
	int					moving;
	struct s_stack		*next;
	struct s_stack		*prev;
	int					num_index;
}						t_stack;

typedef struct			s_ps
{
	t_stack				*a;
	t_stack				*b;
	int					total;
	int					size_a;
	int					size_b;
	t_stack				*head_a;
	t_stack				*tail_a;
	t_stack				*head_b;
	t_stack				*tail_b;
	int					max;
	int					min;
	int					checker_on;
	int					mark_type;
	int					flag;
	t_status			status;
}						t_ps;

void					error_exit(void);
int						*validator(int ac, char **av);
int						counter(char **av);
int						*convert(int count, char **av);
t_ps					*foo_stacks(int count, int *stack);
struct s_stack			*init(int data);
struct s_stack			*addelem(struct s_stack *stack, int data);
void					print_stack_tail(t_ps *all);
void					print_stack_head(t_ps *all);
struct s_stack			*init_empty(void);
struct s_stack			*add_empty(struct s_stack *stack);
void					print_ps(t_ps *all);
void					fill_linked_list(t_ps *all, int *stack);
void					set_index(struct s_stack *stack, int count, t_ps *all);
struct s_stack			*get_next_index(struct s_stack *stack, \
										int count, t_ps *all);
void					sa(t_ps *all);
void					sa_case_1(t_ps *all, t_stack *p1, \
									t_stack *p2, t_stack *p3);
int						sb_ss(t_ps *all);
int						sa_ss(t_ps *all);
void					ra(t_ps *all);
void					rra(t_ps *all);
void					sb(t_ps *all);
void					sb_case_1(t_ps *all, t_stack *p1, \
									t_stack *p2, t_stack *p3);
void					rb(t_ps *all);
int						ra_rr(t_ps *all);
int						rb_rr(t_ps *all);
int						rra_rrr(t_ps *all);
int						rrb_rrr(t_ps *all);
void					rrb(t_ps *all);
void					ss(t_ps *all);
void					rr(t_ps *all);
void					rrr(t_ps *all);
void					copy_data(t_stack *from, t_stack *to);
void					ps_clear_push(t_ps *all, t_stack *a, t_stack *b);
void					pb(t_ps *all);
void					pb_case_1(t_ps *all);
void					pb_case_2(t_ps *all);
void					pb_case_3(t_ps *all);
void					pa(t_ps *all);
void					pa_case_1(t_ps *all);
void					pa_case_2(t_ps *all);
void					pa_case_3(t_ps *all);
void					ps_last_push_clear(t_ps *all, t_stack *a, t_stack *b);
void					do_best_of_three_a(t_ps *all);
void					do_best_of_three_b(t_ps *all);
void					do_for_middle(t_ps *all);
void					go_algo(t_ps *all);
void					reader(t_ps *all);
int						check_command(t_ps *all, char *line);
void					output_args(char **av);
void					output_commands(void);
int						check_if_sorted(t_stack *stack);
void					ft_first_search_mid_and_split(t_ps *all);
void					ft_search_mid_and_split_a(t_ps *all);
void					ft_search_mid_and_split_b(t_ps *all);
void					ft_fill_info(t_ps *all);
void					free_linked_lists(t_ps *all);
void					free_stack(t_stack *stack);

#endif
