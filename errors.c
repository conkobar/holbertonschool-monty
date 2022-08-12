#include "monty.h"

/**
 * errorlocus - directs errors to appropriate output
 * @error: given error
 * @line_number: current line number of .m file
 */
void errorlocus(int error, unsigned int line_number)
{
	switch(error)
	{
		case 0:
			fprintf(stderr, "malloc error");
			break;

		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;

		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", ops[0]);
			break;

		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, ops[0]);
			return;

		case 4:
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;

		default:
			fprintf(stderr, "Unknown Error\n");
			break;
	}


	exit(1);
}
