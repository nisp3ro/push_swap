#include "../include/push_swap.h"

/**
 * @brief Reverse rotates stack_a.
 *
 * Moves the last element of stack_a to the front of the stack.
 * If orderflag is non-zero, prints "rra" to standard output.
 *
 * @param stack_a Double pointer to stack_a.
 * @param orderflag If non-zero, prints the operation ("rra").
 */
void r_rotate_a(t_stack **stack_a, int orderflag)
{
    t_stack *second_last;
    t_stack *last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    second_last = *stack_a;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    if (orderflag)
        ft_putendl_fd("rra", 1);
}

/**
 * @brief Reverse rotates stack_b.
 *
 * Moves the last element of stack_b to the front of the stack.
 * If orderflag is non-zero, prints "rrb" to standard output.
 *
 * @param stack_b Double pointer to stack_b.
 * @param orderflag If non-zero, prints the operation ("rrb").
 */
void r_rotate_b(t_stack **stack_b, int orderflag)
{
    t_stack *second_last;
    t_stack *last;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    second_last = *stack_b;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    if (orderflag)
        ft_putendl_fd("rrb", 1);
}

/**
 * @brief Reverse rotates both stack_a and stack_b simultaneously.
 *
 * Performs a reverse rotation on both stack_a and stack_b by moving their last element
 * to the front. If orderflag is non-zero, prints "rrr" to standard output.
 *
 * @param stack_a Double pointer to stack_a.
 * @param stack_b Double pointer to stack_b.
 * @param orderflag If non-zero, prints the operation ("rrr").
 */
void r_rotate_ab(t_stack **stack_a, t_stack **stack_b, int orderflag)
{
    r_rotate_a(stack_a, 0);
    r_rotate_b(stack_b, 0);
    if (orderflag)
        ft_putendl_fd("rrr", 1);
}
