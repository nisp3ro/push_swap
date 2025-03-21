#include "../include/push_swap.h"

/**
 * @brief Rotates stack_a upwards.
 *
 * Moves the first element of stack_a to the end of the stack.
 * If orderflag is non-zero, prints "ra" to the standard output.
 *
 * @param stack_a Double pointer to the stack_a.
 * @param orderflag If non-zero, prints the operation ("ra").
 */
void rotate_a(t_stack **stack_a, int orderflag)
{
    t_stack *first;
    t_stack *last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    first = *stack_a;
    last = *stack_a;
    while (last->next != NULL)
    {
        last = last->next;
    }
    *stack_a = first->next;
    first->next = NULL;
    last->next = first;
    if (orderflag)
        ft_putendl_fd("ra", 1);
}

/**
 * @brief Rotates stack_b upwards.
 *
 * Moves the first element of stack_b to the end of the stack.
 * If orderflag is non-zero, prints "rb" to the standard output.
 *
 * @param stack_b Double pointer to the stack_b.
 * @param orderflag If non-zero, prints the operation ("rb").
 */
void rotate_b(t_stack **stack_b, int orderflag)
{
    t_stack *first;
    t_stack *last;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    first = *stack_b;
    last = *stack_b;
    while (last->next != NULL)
    {
        last = last->next;
    }
    *stack_b = first->next;
    first->next = NULL;
    last->next = first;
    if (orderflag)
        ft_putendl_fd("rb", 1);
}

/**
 * @brief Rotates both stack_a and stack_b upwards simultaneously.
 *
 * Calls rotate_a and rotate_b with orderflag set to 0 to perform the rotation
 * on both stacks, then prints "rr" if orderflag is non-zero.
 *
 * @param stack_a Double pointer to the stack_a.
 * @param stack_b Double pointer to the stack_b.
 * @param orderflag If non-zero, prints the operation ("rr").
 */
void rotate_ab(t_stack **stack_a, t_stack **stack_b, int orderflag)
{
    rotate_a(stack_a, 0);
    rotate_b(stack_b, 0);
    if (orderflag)
        ft_putendl_fd("rr", 1);
}
