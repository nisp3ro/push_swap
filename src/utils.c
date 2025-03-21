#include "../include/push_swap.h"

/**
 * @brief Counts the number of rotations needed to bring a node with a specific mask to the top.
 *
 * Iterates through the stack until it finds a node whose mask matches the provided value (len).
 *
 * @param stack The stack to search.
 * @param len The mask value to find.
 * @return int The number of rotations (nodes traversed) until the node is found.
 */
int count_r(t_stack *stack, int len)
{
    int counter = 0;

    while (stack && stack->mask != len)
    {
        stack = stack->next;
        counter++;
    }
    return (counter);
}

/**
 * @brief Finds the integer square root of a number using binary search.
 *
 * If n is a perfect square, returns its square root; otherwise, returns the floor of the square root.
 * Returns 0 for negative inputs.
 *
 * @param n The number for which to find the square root.
 * @return int The square root (or floor of the square root) of n.
 */
int find_sqr(int n)
{
    int start;
    int end;
    int mid;

    if (n < 0)
        return (0);
    if (n == 0 || n == 1)
        return (n);
    start = 1;
    end = n / 2;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (mid * mid == n)
            return (mid);
        if (mid * mid < n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return (end);
}

/**
 * @brief Computes the distance (in number of nodes) from the top of the stack to the node with a given mask.
 *
 * Iterates through the stack until a node with a mask equal to the specified minimum value is found.
 *
 * @param stack Double pointer to the stack.
 * @param min The mask value to search for.
 * @return int The number of nodes from the top to the node with the mask equal to min.
 */
int get_distance(t_stack **stack, int min)
{
    t_stack *tmp = *stack;
    int distance = 0;

    while (tmp)
    {
        if (tmp->mask == min)
            break;
        distance++;
        tmp = tmp->next;
    }
    return (distance);
}

/**
 * @brief Finds the minimum mask value in the stack, excluding a specific value.
 *
 * Traverses the stack and returns the smallest mask value found that is not equal to the provided value.
 *
 * @param stack Double pointer to the stack.
 * @param val A mask value to exclude from the search.
 * @return int The smallest mask value found in the stack, excluding val.
 */
int get_min(t_stack **stack, int val)
{
    t_stack *tmp = *stack;
    int min = tmp->mask;

    while (tmp->next)
    {
        tmp = tmp->next;
        if ((tmp->mask < min) && tmp->mask != val)
            min = tmp->mask;
    }
    return (min);
}
