#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "load.h"

short Lab3Rand ()
{
	if (rand () % 2) return (rand () % 51);
	else return -(rand () % 51);
}

int main (void)
{
	char type[7] = "\0";
	short i, j;
	
	printf ("Choose the type of number organization [array/matrix]: ");
	scanf ("%s", type);
	if (strcmp (type, "array") && strcmp (type, "matrix")) exit (271);
	
	if (!strcmp (type, "array"))
	{
		printf ("Generated array:\n");
		short R[38];
		for (i = 0; i < 38; i++)
		{
			R[i] = Lab3Rand ();
			printf ("%3hd ", R[i]);
			if ((i + 1) % 19 == 0) putchar ('\n');
		}
		LoadRun ("arraylib.dll", R, 38);
	}
	
	if (!strcmp (type, "matrix"))
	{
		printf ("Generated matrix:\n");
		short Q[99];
		for (i = 0; i < 99; i++)
		{
			Q[i] = Lab3Rand ();
			printf ("%3hd ", Q[i]);
			if ((i + 1) % 11 == 0) putchar ('\n');
		}
		LoadRun ("matrixlib.dll", Q, 9 * 11);
	}
	
	system ("pause");
	return 0;
}
