#include "../include/push_swap.h"

/**
 * @brief Performs a composite flip on stack_a.
 *
 * This static helper function performs a sequence of operations on stack_a:
 * a rotation, a swap, and a reverse rotation. It is used as part of the sorting
 * strategy for 3-element stacks.
 */
static void do_a_flip(t_stack **stack_a)
{
    rotate_a(stack_a, 1);
    swap_a(stack_a, 1);
    r_rotate_a(stack_a, 1);
}

/**
 * @brief Sorts a stack of 3 elements.
 *
 * This function sorts a stack containing exactly 3 elements based on their mask values.
 * The function assumes that the smallest and the second smallest (min and next_min)
 * are provided.
 *
 * @param stack_a Double pointer to the stack to sort.
 * @param min The smallest mask value in the stack.
 * @param next_min The second smallest mask value in the stack.
 */
void sort_3(t_stack **stack_a, int min, int next_min)
{
    t_stack *tmp = *stack_a;

    if (is_sorted(*stack_a))
        return;
    if (tmp->mask == min && tmp->next->mask != next_min)
        do_a_flip(stack_a);
    else if (tmp->mask == next_min)
    {
        if (tmp->next->mask == min)
            swap_a(stack_a, 1);
        else
            r_rotate_a(stack_a, 1);
    }
    else
    {
        if (tmp->next->mask == min)
            rotate_a(stack_a, 1);
        else
        {
            swap_a(stack_a, 1);
            r_rotate_a(stack_a, 1);
        }
    }
}

/**
 * @brief Sorts a stack of 4 elements.
 *
 * This function sorts a stack with 4 elements by first rotating the stack so that
 * the minimum element (with the smallest mask value) is at the top. It then pushes
 * that element to stack_b, sorts the remaining 3 elements using sort_3, and finally
 * pushes the element back from stack_b to stack_a.
 *
 * @param stack_a Double pointer to the stack_a.
 * @param stack_b Double pointer to the stack_b (used as auxiliary storage).
 */
void sort_4(t_stack **stack_a, t_stack **stack_b)
{
    int distance;

    if (is_sorted(*stack_a))
        return;
    distance = get_distance(stack_a, get_min(stack_a, -1));
    if (distance == 1)
        rotate_a(stack_a, 1);
    else if (distance == 2)
    {
        rotate_a(stack_a, 1);
        rotate_a(stack_a, 1);
    }
    else if (distance == 3)
        r_rotate_a(stack_a, 1);
    if (is_sorted(*stack_a))
        return;
    push_b(stack_a, stack_b, 1);
    sort_3(stack_a, get_min(stack_a, -1), get_min(stack_a, get_min(stack_a, -1)));
    push_a(stack_a, stack_b, 1);
}

/**
 * @brief Sorts a stack of 5 elements.
 *
 * This function sorts a stack with 5 elements by first determining the distance of
 * the smallest element (using get_distance and get_min), rotating the stack accordingly,
 * and pushing the smallest element to stack_b. Then it sorts the remaining 4 elements
 * using sort_4, and finally pushes the smallest element back from stack_b to stack_a.
 *
 * @param stack_a Double pointer to the stack_a.
 * @param stack_b Double pointer to the stack_b (used as auxiliary storage).
 */
void sort_5(t_stack **stack_a, t_stack **stack_b)
{
    int distance;

    distance = get_distance(stack_a, get_min(stack_a, -1));
    if (distance == 1)
        rotate_a(stack_a, 1);
    else if (distance == 2)
    {
        rotate_a(stack_a, 1);
        rotate_a(stack_a, 1);
    }
    else if (distance == 3)
    {
        r_rotate_a(stack_a, 1);
        r_rotate_a(stack_a, 1);
    }
    else if (distance == 4)
        r_rotate_a(stack_a, 1);
    if (is_sorted(*stack_a))
        return;
    push_b(stack_a, stack_b, 1);
    sort_4(stack_a, stack_b);
    push_a(stack_a, stack_b, 1);
}
