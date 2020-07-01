/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:43:48 by wvenita           #+#    #+#             */
/*   Updated: 2020/06/19 02:12:23 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_steps
{
	int				count_a;
	int				count_b;
	int				dest_a;
	int				dest_b;
}					t_steps;

typedef struct		s_data
{
	int				a[10000];
	int				count_element;
}					t_data;

typedef struct		s_stack
{
	int				data;
	int				step;
	int				rotate;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	int				count_a;
	int				count_b;
	int				min;
	int				max;
	int				med;
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

int					ft_only_spaces(const char *str);
int					ft_is_sorted(t_data *new);
int					ft_validation(int ac, char **av);
void				ft_duplicate_check(t_data *new, t_stacks *stacks);
void				ft_array_separation(int ac, char **av, t_data *new);
void				ft_stacking(t_data *new, int *buff, int count);
void				ft_init_stack(t_data *new, t_stacks *stacks);
void				ft_free_stack(t_stacks *stacks);
void				ft_null(t_stacks *stacks, t_data *new);
void				ft_sort_3_element(t_stacks *stacks);
void				ft_sort_5_element(t_stacks *stacks);
void				ft_quick_sort(int *array, int start, int end);
int					ft_partition(int *array, int start, int end);
void				ft_global_sort(t_stacks *stacks);
int					ft_finding_place(t_stacks *s, t_stack *b,
							t_steps *steps, int min);
int					ft_count_to_min(t_stack *a, int min);

void				ft_ra(t_stack **a, int i);
void				ft_rb(t_stack **b, int i);
void				ft_rr(t_stacks *s, int i);
void				ft_rra(t_stack **a, int i);
void				ft_rrb(t_stack **b, int i);
void				ft_sa(t_stack *a, int i);
void				ft_sb(t_stack *a, int i);
void				ft_ss(t_stacks *s, int i);
void				ft_pa(t_stacks *s, int i);
void				ft_pb(t_stacks *s, int i);
void				ft_rrr(t_stacks *s, int i);

int					*ft_intarrcpy(int *dst, const int *src, int count);

#endif
