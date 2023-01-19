#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack
 * @stack: stack
 * @lenum: line number
 *
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int lenum)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		free_global();
		fprintf(stderr, "L%d: can't pint, stack empty\n", lenum);
		exit(EXIT_FAILURE);
	}

	for (; temp->next; temp = temp->next)
		;
	printf("%d\n", temp->n);
}
