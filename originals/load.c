#include "load.h"
#include "funcs.h"
#include <stdio.h>
#include <windows.h>

void LoadRun (const char * const s, short * array, short size)
{
	void * lib;
	void (*fun)(short * array, short size);
	
	lib = LoadLibrary (s);
	if (!lib)
	{
		printf ("Cannot open library '%s'\n", s);
		return;
	}
	
	fun = (void (*)(short int *, short int)) GetProcAddress ((HINSTANCE) lib, "CountMod5");
	if (fun == NULL) printf ("Cannot load function.\n");
	else fun (array, size);
	FreeLibrary ((HINSTANCE) lib);
}
