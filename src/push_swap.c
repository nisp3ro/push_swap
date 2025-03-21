#include "../include/push_swap.h"

/**
 * @brief Sorts the main stack using different strategies based on its size.
 *
 * This function determines the number of elements in stack_a and applies the appropriate
 * sorting strategy:
 * - For 2 elements: a simple swap.
 * - For 3 elements: a specialized sort using sort_3.
 * - For 4 elements: sort_4 is used.
 * - For 5 elements: sort_5 is used.
 * - For more than 5 elements: a chunk sorting strategy is applied by pushing elements
 *   to stack_b and then merging them back in sorted order.
 *
 * @param stack_a Double pointer to the main stack.
 * @param stack_b Double pointer to the auxiliary stack.
 */
void sort(t_stack **stack_a, t_stack **stack_b)
{
    int len;

    len = stack_size(stack_a);
    if (len == 2)
        swap_a(stack_a, 1);
    else if (len == 3)
        sort_3(stack_a, get_min(stack_a, -1), get_min(stack_a, get_min(stack_a, -1)));
    else if (len == 4)
        sort_4(stack_a, stack_b);
    else if (len == 5)
        sort_5(stack_a, stack_b);
    else
    {
        chunk_sort_to_b(stack_a, stack_b, len);
        stack_b_to_a_sorted(stack_a, stack_b, len);
    }
}

/**
 * @brief Validates and allocates arguments into the main stack.
 *
 * This function iterates through the provided arguments (starting at index firstarg),
 * validating each with checker_atoi to ensure they represent valid integers.
 * Then, it calls stack_creator to allocate and populate stack_a.
 *
 * @param argv The argument vector.
 * @param stack_a Double pointer to the main stack.
 * @param firstarg The index of the first argument to process.
 */
void check_and_alloc_args(char **argv, t_stack **stack_a, int firstarg)
{
    int i;

    i = firstarg;
    while (argv[i])
    {
        checker_atoi(argv[i]);
        i++;
    }
    stack_creator(argv, stack_a, firstarg);
}

/**
 * @brief Entry point for the push_swap program.
 *
 * This function builds the initial stack from the command-line arguments.
 * If a single argument is provided, it splits the string into multiple numbers.
 * It then validates the input, allocates stack_a, and checks if it is sorted.
 * If unsorted, it calls the sort function to sort the stack.
 * Finally, it cleans up the allocated memory before exiting.
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @return int Returns 0 upon successful execution.
 */
int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1)
        return (0);
    else if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        check_and_alloc_args(argv, &stack_a, 0);
    }
    else
        check_and_alloc_args(argv, &stack_a, 1);
    if (!is_sorted(stack_a))
        sort(&stack_a, &stack_b);
    clean_stack(&stack_a);
    return (0);
}
