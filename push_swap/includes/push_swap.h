/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:43:08 by aboussem          #+#    #+#             */
/*   Updated: 2025/03/11 10:16:17 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}	t_stack_node;

// stack_utils
t_stack_node    *find_max(t_stack_node *stack);
t_stack_node    *find_min(t_stack_node *stack);
bool	stack_sorted(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
int	stack_len(t_stack_node *stack);

// stack_init
void	init_stack_a(t_stack_node **a, char **argv);
t_stack_node	*get_cheapest(t_stack_node *stack);
void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);

// split
char	**split(char *s, char c);

// sort_three
void    sort_three(t_stack_node **a);

// sort_stack
void    sort_stack(t_stack_node **a, t_stack_node **b);

// rotate
void	ra(t_stack_node **a, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	rb(t_stack_node **b, bool print);

// swap
void	sa(t_stack_node	**a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);

// handle_errors
int	error_syntax(char *str_n);
int	error_duplicate(t_stack_node *a, int n);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **a);

// push
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);

// rev_rotate
void	rrr(t_stack_node **a, t_stack_node **b, bool print);
void	rrb(t_stack_node **b, bool print);
void	rra(t_stack_node **a, bool print);


// init_b_to_a
void    init_nodes_b(t_stack_node *a, t_stack_node *b);

// init_a_to_b
void	set_cheapest(t_stack_node *stack);
void    init_nodes_a(t_stack_node *a, t_stack_node *b);
void	current_index(t_stack_node *stack);









#endif
