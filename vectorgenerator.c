#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int midval(int* vector,int ext1,int ext2)
{
	int midincrement = rand() % 10;
	int midval;

	midval = (rand() % 2) == 0 ?
	((vector[ext1] + vector[ext2]) / 2) - midincrement :
	((vector[ext1] + vector[ext2]) / 2) + midincrement;
	
	return midval;
}

int* genvec(int* vector, int len, int ext1, int ext2, int flag)
{
	int mid = (ext1 + ext2) / 2;

	if(flag == 0)
	{
		vector[ext1] = rand() % 100;
		vector[ext2] = rand() % 100;
		vector[mid] = midval(vector, ext1, ext2);
		flag++;
		genvec(vector, len / 2, ext1, mid, flag);
		genvec(vector, len / 2, mid, ext2, flag);
	}
	else
	{
		if(vector[mid+1] != 0 && vector[mid-1] != 0)
		{
			vector[mid] = midval(vector, ext1, ext2);
			return vector;
		} 
		vector[mid] = midval(vector, ext1, ext2);	
		genvec(vector, len / 2, ext1, mid, flag);
		genvec(vector, len / 2, mid, ext2, flag);
	}
}