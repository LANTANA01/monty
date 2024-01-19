#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n:  integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*Functions for File operations*/
void open_file_func(char *file_name);
int parse_line_func(char *buffer, int line_num, int format);
void read_file_func(FILE *);
int len_chars(FILE *);
void find_funct(char *, char *, int, int);

/*Functions for Stack operations*/
stack_t *create_node(int value);
void free_nodes(void);
void print_stack_itm(stack_t **, unsigned int);
void add_to_a_stack(stack_t **, unsigned int);
void add_to_a_queue(stack_t **, unsigned int);

void call_func(op_func, char *, char *, int, int);

void print_top_itm(stack_t **, unsigned int);
void pop_top_itm(stack_t **, unsigned int);
void f_nop(stack_t **, unsigned int);
void swap_nodes_itm(stack_t **, unsigned int);

/*Functions for Math operations with nodes*/
void add_nodes_itm(stack_t **, unsigned int);
void sub_nodes_itm(stack_t **, unsigned int);
void div_nodes_itm(stack_t **, unsigned int);
void mul_nodes_itm(stack_t **, unsigned int);
void mod_nodes_itm(stack_t **, unsigned int);

/*Functions for String operations*/
void print_char_itm(stack_t **, unsigned int);
void print_str_itm(stack_t **, unsigned int);
void rotl_itm(stack_t **, unsigned int);

/*Functions for Error hanlding*/
void err_msg(int error_code, ...);
void more_err_msg(int error_code, ...);
void string_err_msg(int error_code, ...);
void rotr_itm(stack_t **, unsigned int);

#endif /* end of MONTY_H */
