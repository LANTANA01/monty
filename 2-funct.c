#include "monty.h"

/**
 *f_ nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes_itm - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void swap_nodes_itm(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err_msg(8, line_num, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes_itm - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void add_nodes_itm(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err_msg(8, line_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes_itm - Sustracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void sub_nodes_itm(stack_t **stack, unsigned int line_num)
{
	int subt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err_msg(8, line_num, "sub");


	(*stack) = (*stack)->next;
	subt = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = subt;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes_itm - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void div_nodes_itm(stack_t **stack, unsigned int line_num)
{
	int divd;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err_msg(8, line_num, "div");

	if ((*stack)->n == 0)
		more_err_msg(9, line_num);
	(*stack) = (*stack)->next;
	divd = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = divd;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
