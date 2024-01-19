#include "monty.h"

/**
 * mul_nodes_itm - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void mul_nodes_itm(stack_t **stack, unsigned int line_num)
{
	int multpl;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err_msg(8, line_num, "mul");

	(*stack) = (*stack)->next;
	multpl = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = multpl;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes_itm - Gives modulus of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void mod_nodes_itm(stack_t **stack, unsigned int line_num)
{
	int modu;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err_msg(8, line_num, "mod");


	if ((*stack)->n == 0)
		more_err_msg(9, line_num);
	(*stack) = (*stack)->next;
	modu = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = modu;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
