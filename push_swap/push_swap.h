/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:45:32 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/12 15:45:34 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_sa(int **a, int len_a, int is_ss);
void	ft_sb(int **b, int len_b, int is_ss);
void	ft_ss(int **a, int len_a, int **b, int len_b);
void	ft_pa(int **a, int *len_a, int **b, int *len_b);
void	ft_pb(int **a, int *len_a, int **b, int *len_b);
void	ft_ra(int **a, int len_a, int is_rr);
void	ft_rb(int **b, int len_b, int is_rr);
void	ft_rr(int **a, int len_a, int **b, int len_b);
void	ft_rra(int **a, int len_a, int is_rrr);
void	ft_rrb(int **b, int len_b, int is_rrr);
void	ft_rrr(int **a, int len_a, int **b, int len_b);
int		ft_atoi(const char *str);
void	ft_parse_a(int **a, int *len_a, int argc, char **argv);
size_t	ft_strlen(const char *s);
int		ft_error(void);
char	**ft_split(char const *s, char c);
void	parse_str(char *s, int **a, int *len_a);
void	ft_sort_arr(int **arr, int len_arr);
void	ft_sort(int **a, int len_a);
int		ft_find_median(int *arr, int len_arr);
void	ft_to_top(int **arr, int len_arr, int ind_el);

#endif