#include "monty.h"

/**
 * open_file_func - this opens a file
 * @file_name: the file namepath
 * Return: void
 */

void open_file_func(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err_msg(2, file_name);

	read_file_func(fd);
	fclose(fd);
}


/**
 * read_file_func - this reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file_func(FILE *fd)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buffer, &len, fd) != -1; line_num++)
	{
		format = parse_line_func(buffer, line_num, format);
	}
	free(buffer);
}


/**
 * parse_line_func - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_num: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line_func(char *buffer, int line_num, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err_msg(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_funct(opcode, value, line_num, format);
	return (format);
}

/**
 * find_funct - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_funct(char *opcode, char *value, int line_num, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_a_stack},
		{"pall", print_stack_itm},
		{"pint", print_top_itm},
		{"pop", pop_top_itm},
		{"nop", f_nop},
		{"swap", swap_nodes_itm},
		{"add", add_nodes_itm},
		{"sub", sub_nodes_itm},
		{"div", div_nodes_itm},
		{"mul", mul_nodes_itm},
		{"mod", mod_nodes_itm},
		{"pchar", print_char_itm},
		{"pstr", print_str_itm},
		{"rotl", rotl_itm},
		{"rotr", rotr_itm},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_func(func_list[i].f, opcode, value, line_num, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err_msg(3, line_num, opcode);
}


/**
 * call_func - This calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @line_num: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_func(op_func func, char *op, char *val, int line_num, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err_msg(5, line_num);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err_msg(5, line_num);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, line_num);
		if (format == 1)
			add_to_a_queue(&node, line_num);
	}
	else
		func(&head, line_num);
}
