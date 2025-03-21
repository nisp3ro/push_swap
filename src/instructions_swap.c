#include "../include/push_swap.h"

/**
 * @brief Swaps the first two elements of stack_a.
 *
 * This function exchanges the positions of the first two nodes in stack_a.
 * If the orderflag is non-zero, it prints "sa" to standard output.
 *
 * @param stack_a Double pointer to stack_a.
 * @param orderflag If non-zero, prints the operation ("sa").
 */
void swap_a(t_stack **stack_a, int orderflag)
{
    t_stack *first;
    t_stack *second;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    if (orderflag)
        ft_putendl_fd("sa", 1);
}

/**
 * @brief Swaps the first two elements of stack_b.
 *
 * This function exchanges the positions of the first two nodes in stack_b.
 * If the orderflag is non-zero, it prints "sb" to standard output.
 *
 * @param stack_b Double pointer to stack_b.
 * @param orderflag If non-zero, prints the operation ("sb").
 */
void swap_b(t_stack **stack_b, int orderflag)
{
    t_stack *first;
    t_stack *second;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    first = *stack_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
    if (orderflag)
        ft_putendl_fd("sb", 1);
}

/**
 * @brief Swaps the first two elements of both stack_a and stack_b.
 *
 * This function performs swap_a and swap_b simultaneously. If orderflag is non-zero,
 * it prints "ss" to standard output.
 *
 * @param stack_a Double pointer to stack_a.
 * @param stack_b Double pointer to stack_b.
 * @param orderflag If non-zero, prints the operation ("ss").
 */
void swap_ab(t_stack **stack_a, t_stack **stack_b, int orderflag)
{
    swap_a(stack_a, 0);
    swap_b(stack_b, 0);
    if (orderflag)
        ft_putendl_fd("ss", 1);
}
