#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structures.h"
#include "functions.h"
#include "ppmgenerator.h"

int main(int argc, char* argv[])
{
	unsigned int columns = 129;

	// Pega o tamanho da imagem fornecido em linha de comando.
	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i],"-s") == 0)
		{
			sscanf(argv[i+1], "%d", &columns);
			//lines = argv[i+1];
		}
	}

	unsigned int lines = columns / 2; // A largura e altura da imagem vão ser iguais.

	int displacement = 10; // Deslocamento máximo recebido por parâmetro de configuração.

	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i],"-d") == 0)
		{
			sscanf(argv[i+1], "%d", &displacement);
			//displacement = argv[i+1];
		}
	}

	int* vector;

	vector = calloc(columns, sizeof(int));
	vector = genvec(vector, columns, 0, columns-1, displacement, 0);

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