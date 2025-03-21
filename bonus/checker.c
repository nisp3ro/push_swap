#include "../include/push_swap.h"

/**
 * @brief Executes a move command on the stacks.
 *
 * Compares the given command string (with newline) to known push_swap operations,
 * and executes the corresponding operation on the provided stacks.
 *
 * @param cmd The command string (e.g., "pa\n", "rb\n").
 * @param stack_a Double pointer to stack_a.
 * @param stack_b Double pointer to stack_b.
 * @return int Returns 1 if a valid command was executed, or 0 if the command is invalid.
 */
int do_the_move(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
    if (!ft_strncmp(cmd, "pa\n", 3))
        push_a(stack_a, stack_b, 0);
    else if (!ft_strncmp(cmd, "pb\n", 3))
        push_b(stack_a, stack_b, 0);
    else if (!ft_strncmp(cmd, "sa\n", 3))
        swap_a(stack_a, 0);
    else if (!ft_strncmp(cmd, "sb\n", 3))
        swap_b(stack_b, 0);
    else if (!ft_strncmp(cmd, "ss\n", 3))
        swap_ab(stack_a, stack_b, 0);
    else if (!ft_strncmp(cmd, "ra\n", 3))
        rotate_a(stack_a, 0);
    else if (!ft_strncmp(cmd, "rb\n", 3))
        rotate_b(stack_b, 0);
    else if (!ft_strncmp(cmd, "rr\n", 3))
        rotate_ab(stack_a, stack_b, 0);
    else if (!ft_strncmp(cmd, "rra\n", 4))
        r_rotate_a(stack_a, 0);
    else if (!ft_strncmp(cmd, "rrb\n", 4))
        r_rotate_b(stack_b, 0);
    else if (!ft_strncmp(cmd, "rrr\n", 4))
        r_rotate_ab(stack_a, stack_b, 0);
    else
        return (0);
    return (1);
}

/**
 * @brief Reads commands from standard input and executes them on the stacks.
 *
 * Continuously reads lines from STDIN (using get_next_line) and applies each command to the
 * stacks. If an invalid command is encountered, the function cleans up both stacks,
 * prints an error message, and terminates the program.
 *
 * @param stack_a Double pointer to stack_a.
 * @param stack_b Double pointer to stack_b.
 */
void rd_n_ex_cmd(t_stack **stack_a, t_stack **stack_b)
{
    char *line;

    line = get_next_line(STDIN_FILENO);
    while (line)
    {
        if (!do_the_move(line, stack_a, stack_b))
        {
            free(line);
            clean_stack(stack_a);
            clean_stack(stack_b);
            ft_putendl_fd("Error", STDOUT_FILENO);
            exit(EXIT_FAILURE);
        }
        free(line);
        line = get_next_line(STDIN_FILENO);
    }
}

/**
 * @brief Validates and allocates command-line arguments into the stack.
 *
 * Checks each argument (starting at firstarg) with checker_atoi to ensure they represent
 * valid integers, then creates the stack using stack_creator.
 *
 * @param argv The array of argument strings.
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
 * @brief Main entry point for the push_swap checker.
 *
 * Builds the initial stack from the command-line arguments. If only one argument is provided,
 * it splits the string into multiple numbers. Then, it reads commands from standard input and
 * executes them on the stacks. Finally, it prints "OK" if the stack is sorted, or "KO" otherwise,
 * and cleans up the allocated memory.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line argument strings.
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
    rd_n_ex_cmd(&stack_a, &stack_b);
    if (is_sorted(stack_a))
        ft_putendl_fd("OK", STDOUT_FILENO);
    else
        ft_putendl_fd("KO", STDOUT_FILENO);
    clean_stack(&stack_a);
    return (0);
}
