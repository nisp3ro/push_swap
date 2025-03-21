#include "../include/push_swap.h"

/**
 * @brief Pushes the top element from stack_b to stack_a.
 *
 * This function removes the first node from stack_b and inserts it at the top
 * of stack_a. If the orderflag is set, it prints "pa" to standard output.
 *
 * @param stack_a Double pointer to the stack_a.
 * @param stack_b Double pointer to the stack_b.
 * @param orderflag If non-zero, prints the operation ("pa") to standard output.
 */
void push_a(t_stack **stack_a, t_stack **stack_b, int orderflag)
{
    t_stack *node_to_push;

    if (*stack_b == NULL)
        return;
    node_to_push = *stack_b;
    *stack_b = (*stack_b)->next;
    node_to_push->next = *stack_a;
    *stack_a = node_to_push;
    if (orderflag)
        ft_putendl_fd("pa", 1);
}

/**
 * @brief Pushes the top element from stack_a to stack_b.
 *
 * This function removes the first node from stack_a and inserts it at the top
 * of stack_b. If the orderflag is set, it prints "pb" to standard output.
 *
 * @param stack_a Double pointer to the stack_a.
 * @param stack_b Double pointer to the stack_b.
 * @param orderflag If non-zero, prints the operation ("pb") to standard output.
 */
void push_b(t_stack **stack_a, t_stack **stack_b, int orderflag)
{
    t_stack *node_to_push;

    if (*stack_a == NULL)
        return;
    node_to_push = *stack_a;
    *stack_a = (*stack_a)->next;
    node_to_push->next = *stack_b;
    *stack_b = node_to_push;
    if (orderflag)
        ft_putendl_fd("pb", 1);
}
