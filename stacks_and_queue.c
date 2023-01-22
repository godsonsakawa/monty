#include "monty.h"

/**
 * _queue - sets format of data to queue(FIFI/LILO)
 * @doubly: head of linked list
 * @cline: line number
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * _stack - sets format of data to stack (LIFO/FILO)
 * @doubly: linked list head
 * @cline: line number
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}
