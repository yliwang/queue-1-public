#include <stdio.h>

#include "stack.h"

void main()
{
	/* */
	struct stack *s;
	s = create_stack();

  /* other test code */

	free(s);
}
