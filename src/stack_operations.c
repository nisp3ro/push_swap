#include "../include/push_swap.h"

/**
 * @brief Calculates the size of a stack.
 *
 * Iterates through the linked list representing the stack and counts the number
 * of nodes.
 *
 * @param lst Double pointer to the head of the stack.
 * @return int The number of elements in the stack.
 */
int stack_size(t_stack **lst)
{
    t_stack *temp;
    int size;

    temp = *lst;
    size = 0;
    while (temp)
    {
        temp = temp->next;
        size++;
    }
    return (size);
}

/**
 * @brief Retrieves the last node in the stack.
 *
 * Traverses the linked list until the last node is found.
 *
 * @param lst Pointer to the head of the stack.
 * @return t_stack* Pointer to the last node of the stack.
 */
t_stack *stack_last(t_stack *lst)
{
    while (lst && lst->next)
        lst = lst->next;
    return (lst);
}

/**
 * @brief Frees all nodes in the stack.
 *
 * Iterates through the stack and frees each node, setting the head pointer to NULL.
 *
 * @param lst Double pointer to the head of the stack.
 */
void clean_stack(t_stack **lst)
{
    t_stack *temp;

    while (*lst)
    {
        temp = (*lst)->next;
        free(*lst);
        *lst = temp;
    }
}

/**
 * @brief Adds a new node to the back of the stack.
 *
 * If the stack is empty, the new node becomes the head. Otherwise, the function
 * traverses to the end of the stack and appends the new node.
 *
 * @param lst Double pointer to the head of the stack.
 * @param new The new node to add.
 */
void stack_add_back(t_stack **lst, t_stack *new)
{
    t_stack *last;

    if (*lst == NULL)
        *lst = new;
    else
    {
        last = stack_last(*lst);
        last->next = new;
    }
}

/**
 * @brief Creates a new stack node.
 *
 * Allocates memory for a new node, initializes it with the given number, sets
 * the mask to 0, and initializes the next pointer to NULL.
 *
 * @param nb The integer value to store in the node.
 * @return t_stack* Pointer to the newly created node, or NULL if allocation fails.
 */
t_stack *new_stack_node(int nb)
{
    t_stack *newlist;

    newlist = malloc(sizeof(t_stack));
    if (!newlist)
        return (NULL);
    newlist->nb = nb;
    newlist->mask = 0;
    newlist->next = NULL;
    return (newlist);
}
