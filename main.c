#include <string.h>

#include "structures.h"
#include "ppmgenerator.h"
#include "vectorgenerator.h"

int main(int argc, char* argv[])
{
	const unsigned int lines = 120;
	const unsigned int columns = 160;

	int* vector;

	vector = calloc(columns, sizeof(int));
	vector = genvec(vector, columns, 0, columns-1, 0);

	if(argc < 2) createppm("default.ppm", "w", lines, columns, vector);
	else
	{
		for(int i = 0; i < argc; i++)
		{
			if(strcmp(argv[i],"-o") == 0)
			{
				createppm(argv[i+1], "w", lines, columns, vector);
			}
		}
	}
	
	return 0;
}