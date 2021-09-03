#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structures.h"

/** 
* \brief Função destinada a seleção das cores posicionadas no fundo e pelo vetor.
* \param matrix Ponteiro de ponteiro do tipo Pixel destinado a definição de valor 
*		 das posições.
* \param lines Valor com o número de linhas da matriz
* \param columns Valor com o número de colunas da matriz
* \param vector Ponteiro do tipo inteiro contendo o os valores que definem as 
*		 posições a populadas com seu respectivos valores
*/
void paintmatrix(Pixel** matrix, int lines, int columns, int* vector)
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

/** 
* \brief Função destinada a calcular o valor do ponto do meio.
* \param vector Ponteiro do tipo inteiro que armazenará os valores.
* \param ext1 Valor de um dos extremos usado para calcular o valor do meio.
* \param ext2 Valor do outro extremo usado para calcular o valor do meio.
* \param max_disp Valor do deslocamento máximo.
*/
int midval(int* vector,int ext1,int ext2, int max_disp)
{
	int midincrement = rand() % max_disp; //número aleatório que vai ser incrementado ao valor do meio.
	int midval;

	// Gera um número 0 ou 1, para saber se o midincrement vai ser incrementado ou decrementado.
	midval = (rand() % 2) == 0 ?
	((vector[ext1] + vector[ext2]) / 2) - midincrement :
	((vector[ext1] + vector[ext2]) / 2) + midincrement;
	
	return midval;
}

/** 
* \brief Função destinada a gerar o vetor de altitudes.
* \param vector Ponteiro do tipo inteiro que armazenará os valores.
* \param len Quantidade de valores no vetor.
* \param ext1 Valor de um dos extremos usado para calcular o valor do meio.
* \param ext2 Valor do outro extremo usado para calcular o valor do meio.
* \param disp Valor do deslocamento aleatório máximo. 
*/
int* genvec(int* vector, int len, int ext1, int ext2, int disp, int flag)
{
	// Índice do vetor em que está localizado o ponto médio, atualizado a cada recursão.
	int mid = (ext1 + ext2) / 2;

	// Na primeira recursão ele vai definir os extremos aleatoriamente e definir o ponto do meio.
	if(flag == 0)
	{
		vector[ext1] = rand() % 100;
		vector[ext2] = rand() % 100;
		vector[mid] = midval(vector, ext1, ext2, disp);
		flag++;
		genvec(vector, len / 2, ext1, mid, disp, flag);
		genvec(vector, len / 2, mid, ext2, disp, flag);
	}
	else
	{
		if(vector[mid+1] != 0 && vector[mid-1] != 0)
		{
			vector[mid] = midval(vector, ext1, ext2, disp);
			return vector;
		} 
		vector[mid] = midval(vector, ext1, ext2, disp);	
		genvec(vector, len / 2, ext1, mid, disp, flag);
		genvec(vector, len / 2, mid, ext2, disp, flag);
	}
}