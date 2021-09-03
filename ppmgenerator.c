#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "functions.h"

/* 
* Função destinada a criar o arquivo ppm e a escrever no mesmo com base na matriz. 
*/
void createppm(char name[20], char mode[5], int lines, int columns, int* vector)
{

	FILE *fp = fopen(name, mode);

	Pixel** matrixcolor;

	matrixcolor = malloc(sizeof(Pixel*) * lines);

	for(int i = 0; i < lines; i++)
	{
		matrixcolor[i] = malloc(sizeof(Pixel) * columns);
	}

	paintmatrix(matrixcolor, lines, columns, vector);

	if(fp == NULL) printf("Falha ao tentar criar arquivo ppm!");
	else
	{
		fprintf(fp,"P3\n%d %d\n255\n", columns, lines);

		for(int i = 0; i < lines; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				fprintf(fp, "%d %d %d\n", matrixcolor[i][j].R, matrixcolor[i][j].G, matrixcolor[i][j].B);
			}
		}
		fclose(fp);
	}
}
