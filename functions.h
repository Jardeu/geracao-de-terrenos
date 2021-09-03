// Função para criar o arquivo ppm e a escrever no mesmo com base na matriz.
void paintmatrix(Pixel** matrix, int lines, int columns, int* vector);

// Função que calcula o valor do ponto do meio.
int midval(int* vector,int ext1,int ext2);

// Função para gerar o valor das altitudes.
int* genvec(int* vector, int len, int ext1, int ext2, int disp, int flag);
