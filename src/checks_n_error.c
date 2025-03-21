#include "../include/push_swap.h"

/**
 * @brief Prints an error message and exits the program.
 *
 * This function writes "Error" to the standard error output and terminates the program.
 */
void error_exit(void)
{
    ft_putendl_fd("Error", STDERR_FILENO);
    exit(EXIT_FAILURE);
}

/**
 * @brief Checks if the stack is sorted in ascending order based on the mask value.
 *
 * Iterates through the linked list representing the stack and verifies that each element's
 * mask is less than or equal to the next element's mask.
 *
 * @param stack The pointer to the top of the stack.
 * @return int Returns 1 if the stack is sorted, 0 otherwise.
 */
int is_sorted(t_stack *stack)
{
    t_stack *tmp = stack;
    while (tmp->next)
    {
        if (tmp->mask > tmp->next->mask)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

/**
 * @brief Checks for duplicate mask values in the stack.
 *
 * Iterates through the stack using a two-pointer technique. If any duplicate mask values
 * are found, the function cleans the stack and calls error_exit() to terminate the program.
 *
 * @param stack_a The pointer to the top of the stack to check.
 */
void check_duplicates(t_stack *stack_a)
{
    t_stack *current = stack_a;
    t_stack *runner;

    while (current)
    {
        runner = current->next;
        while (runner)
        {
            if (current->mask == runner->mask)
            {
                clean_stack(&stack_a);
                error_exit();
            }
            runner = runner->next;
        }
        current = current->next;
    }
}

/**
 * @brief Validates and converts a string to an integer.
 *
 * This function processes the input string, ignoring any leading whitespace,
 * and converts it to an integer. If the string contains any invalid characters
 * or if the resulting value is out of the integer range, it calls error_exit().
 *
 * @param str The string to validate and convert.
 */
void checker_atoi(const char *str)
{
    int i = 0;
    long long int res = 0;
    int sing = -1;  /* Using -1 to account for sign inversion in calculation */

    /* Skip any whitespace characters */
    while (str[i] == 9 || str[i] == 10 || str[i] == 11 || 
           str[i] == 12 || str[i] == 13 || str[i] == 32)
        i++;
    
    /* Handle optional sign */
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sing = 1;
        i++;
    }
    
    /* Process digits */
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            error_exit();
        res = (res * 10) - (str[i] - '0');
        i++;
    }
    
    /* Check for overflow/underflow */
    if ((res * sing) > INT_MAX || (res * sing) < INT_MIN)
        error_exit();
}
