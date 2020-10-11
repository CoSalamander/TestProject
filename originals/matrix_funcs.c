#include <stdio.h> 
#include "funcs.h"

void CountMod5 (short * array, short size)
{
	short i, count = 0;
	for (i = 0; i < size; i++)
		if (array[i] % 5 == 1) count++;
	printf ("Counted elements: %d\n", count);
}
