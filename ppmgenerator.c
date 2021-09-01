#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

/** 
* \brief Função destinada a seleção das cores posicionadas no fundo e pelo vetor.
* \param matrix Ponteiro de ponteiro do tipo Color destinado a definição de valor 
*		 das posições.
* \param lines Valor com o número de linhas da matriz
* \param columns Valor com o número de colunas da matriz
* \param vector Ponteiro do tipo inteiro contendo o os valores que definem as 
*		 posições a populadas com seu respectivos valores
*/
void paintmatrix(Color** matrix, int lines, int columns, int* vector)
{
	for(int i = 0; i < lines; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			if(i >= vector[j])
			{
				matrix[i][j].R = 25;
				matrix[i][j].G = 29;
				matrix[i][j].B = 76;
			}else
			{
				matrix[i][j].R = 17;
				matrix[i][j].G = 14;
				matrix[i][j].B = 25;
			}
		}
	}
}


/* 
* Função destinada a criar o arquivo ppm e a esquever no mesmo com base na matriz. 
*/
void createppm(char name[20], char mode[5], int lines, int columns, int* vector)
{

	FILE *fp = fopen(name, mode);

	Color** matrixcolor;

	matrixcolor = malloc(sizeof(Color*) * lines);

	for(int i = 0; i < lines; i++)
	{
		matrixcolor[i] = malloc(sizeof(Color) * columns);
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
