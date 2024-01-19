#include "monty.h"

/**
 * err_msg - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => user does not give any file or more than one file to the program.
 * (2) => file provided is not a file that can be opened or read.
 * (3) => file provided contains an invalid instruction.
 * (4) => program is unable to malloc more memory.
 * (5) => parameter passed to the instruction "push" is not an int.
 * (6) => stack is empty for pint.
 * (7) => stack is empty for pop.
 * (8) => stack is too short for operation.
 */
void err_msg(int error_code, ...)
{
	va_list ag;
	char *op;
	int line_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			line_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err_msg - handles errors.
 * @error_code: The error codes are the following:
 * (6) => stack is empty for pint.
 * (7) => stack is empty for pop.
 * (8) => stack is too short for operation.
 * (9) => division by zero.
 */
void more_err_msg(int error_code, ...)
{
	va_list ag;
	char *op;
	int line_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			line_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err_msg - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> number inside a node is outside ASCII bounds.
 * (11) ~> stack is empty.
 */
void string_err_msg(int error_code, ...)
{
	va_list ag;
	int line_num;

	va_start(ag, error_code);
	line_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
