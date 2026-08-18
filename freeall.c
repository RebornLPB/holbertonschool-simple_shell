#include "main.h"

/**
 * free_all - Frees memory for up to three pointers
 * @number1: First pointer to free
 * @number2: Second pointer to free
 * @number3: Third pointer to free
 *
 * Return: void
 */
void free_all(void *number1, void *number2, void *number3)
{
	if (number1)
		free(number1);
	if (number2)
		free(number2);
	if (number3)
		free(number3);
}
