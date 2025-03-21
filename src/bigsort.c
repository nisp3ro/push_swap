#include "../include/push_swap.h"

/**
 * @brief Moves elements from stack_b back to stack_a in sorted order.
 *
 * This function takes the element with the highest mask value (equal to len - 1)
 * from stack_b and moves it to stack_a, ensuring that the stack_a remains sorted.
 * It determines the optimal rotation direction (rotate or reverse rotate) based on
 * the number of moves required and performs the necessary rotations before pushing.
 *
 * @param stack_a Double pointer to stack_a.
 * @param stack_b Double pointer to stack_b.
 * @param len The number of elements (or the maximum mask value + 1) to be considered from stack_b.
 */
void stack_b_to_a_sorted(t_stack **stack_a, t_stack **stack_b, int len)
{
    int rb_count;
    int rrb_count;

    while (len - 1 >= 0)
    {
        rb_count = count_r((*stack_b), len - 1);
        rrb_count = len - rb_count;
        if (rb_count <= rrb_count)
        {
            while ((*stack_b)->mask != len - 1)
                rotate_b(stack_b, 1);
            push_a(stack_a, stack_b, 1);
            len--;
        }
        else
        {
            while ((*stack_b)->mask != len - 1)
                r_rotate_b(stack_b, 1);
            push_a(stack_a, stack_b, 1);
            len--;
        }
    }
}

/**
 * @brief Sorts elements from stack_a into stack_b using a chunk sorting strategy.
 *
 * This function partitions the elements of stack_a based on their mask values and moves them to
 * stack_b. Elements with a mask value less than or equal to the current threshold (i) are pushed
 * to stack_b and then rotated, while those within the next range (i + range) are simply pushed.
 * If an element's mask exceeds these thresholds, stack_a is rotated to bring other elements to the top.
 *
 * @param stack_a Double pointer to stack_a.
 * @param stack_b Double pointer to stack_b.
 * @param len The total number of elements initially present in stack_a.
 */
void chunk_sort_to_b(t_stack **stack_a, t_stack **stack_b, int len)
{
    int i;
    int range;

    i = 0;
    range = find_sqr(len) * 14 / 10;
    while (*stack_a)
    {
        if ((*stack_a)->mask <= i)
        {
            push_b(stack_a, stack_b, 1);
            rotate_b(stack_b, 1);
            i++;
        }
        else if ((*stack_a)->mask <= i + range)
        {
            push_b(stack_a, stack_b, 1);
            i++;
        }
        else
            rotate_a(stack_a, 1);
    }
}
