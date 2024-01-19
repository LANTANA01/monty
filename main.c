#include "monty.h"
stack_t *head = NULL;

/**
 * main - The entry point
 * @arg_count: arguments count
 * @arg_list: list of arguments
 * Return: always 0
 */

int main(int arg_count, char *arg_list[])
{
	if (arg_count != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file_func(arg_list[1]);
	free_nodes();
	return (0);
}

/**
 * create_node- This creates a node.
 * @value: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		err_msg(4);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = value;
	return (new_node);
}

/**
 * free_nodes - This frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_to_a_queue - This adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_a_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
