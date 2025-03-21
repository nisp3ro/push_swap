#include "../include/push_swap.h"

/**
 * @brief Normalizes the stack by assigning rank-based mask values.
 *
 * Iterates through the entire stack and, for each node, counts the number of nodes
 * with a smaller value. This count is then assigned as the node's mask, effectively
 * normalizing the stack based on the relative order of its elements.
 *
 * @param stack_a Pointer to the head of the stack.
 */
void normalize_stack(t_stack *stack_a)
{
    t_stack *i;
    t_stack *j;
    int index;

    i = stack_a;
    while (i)
    {
        index = 0;
        j = stack_a;
        while (j)
        {
            if (j->nb < i->nb)
                index++;
            j = j->next;
        }
        i->mask = index;
        i = i->next;
    }
}

/**
 * @brief Creates a stack from an array of string arguments.
 *
 * This function processes the provided array of strings (starting at the given index)
 * and converts each string to an integer using ft_atoi. For each integer, it creates a new
 * stack node and appends it to the end of the stack. If the arguments were provided as a single
 * string (i.e. firstarg is 0), the function frees the allocated array after processing.
 *
 * After building the stack, the function normalizes it by assigning mask values based on the
 * relative order of the numbers and checks for duplicate values.
 *
 * @param argv Array of strings representing the input numbers.
 * @param stack_a Double pointer to the head of the stack that will be created.
 * @param firstarg The index of the first argument to process in argv.
 */
void stack_creator(char **argv, t_stack **stack_a, int firstarg)
{
    int zeroifalloc;
    t_stack *node;

    zeroifalloc = firstarg;
    while (argv[firstarg])
    {
        node = new_stack_node(ft_atoi(argv[firstarg]));
        if (!node)
        {
            clean_stack(stack_a);
            ft_putendl_fd("Error", STDERR_FILENO);
            exit(EXIT_FAILURE);
        }
        stack_add_back(stack_a, node);
        firstarg++;
    }
    if (zeroifalloc == 0)
    {
        while (argv[zeroifalloc])
            free(argv[zeroifalloc++]);
        free(argv);
    }
    normalize_stack(*stack_a);
    check_duplicates(*stack_a);
}
