/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:48:47 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/15 21:06:03 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
#define FT_PUSH_SWAP_H

#include "libft.h"

#include <stdio.h>

typedef struct s_stack
{
	int val;
	int i;
	int sort;
	struct s_stack *next;
} t_stack;

typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
	t_stack *max_sort;
	int len_a;
	int len_b;
	int opt_a;
	int opt_b;
	int opt_pl;
	int tmp_a;
	int tmp_b;
	int tmp_pl;
	int cmd_print;
	int cmds_cnt;
	int flag_v;
	int flag_c;
} t_stacks;

t_stacks *ft_create_stacks(int ac, char **av);
int ft_is_dupl(t_stack *stack, int val);

void ft_cmd_instr_cnt(char *instr, int count, t_stacks *stacks);
void ft_print_stack(t_stacks *stacks);
int ft_get_count_list(t_stack *stack);

t_stack *ft_stack_pop_back(t_stack **stack);
void ft_stack_push_back(t_stack **stack, t_stack *new);
t_stack *ft_stack_pop_front(t_stack **stack);
void ft_stack_push_front(t_stack **stack, t_stack *new);

int ft_cmd_instr_s(t_stack **stack);
int ft_cmd_instr_r(t_stack **stack);
int ft_cmd_instr_rr(t_stack **stack);
int ft_cmd_instr_p(t_stack **from, t_stack **to);

int ft_stacks_free(t_stacks **stacks, int return_val);
void ft_put_error(t_stacks **stacks, int return_value);
void ft_st_copy_tmp_to_opt_cmds(t_stacks *stacks);
int ft_st_set_tmp_cmds(t_stacks *stacks, t_stack *stack_b);

void ft_st_a_norm(t_stacks *stacks);
void ft_st_a_to_b(t_stacks *stacks);
void ft_st_b_to_a(t_stacks *stacks);
void ft_list_b_to_a(t_stacks *stacks);
void ft_st_a_min_to_top(t_stacks *stacks);
void ft_set_index(t_stack *stack);
t_stack *ft_get_max_sort(t_stack *stack);
int ft_list_iter_to_up(int stack_len, int list_i);
int ft_get_list_place_i(t_stack *stack, int list_val);
int ft_list_b_to_a_count(int a, int b, int place_b);

#endif