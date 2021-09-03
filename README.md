# geracao-de-terrenos
Projeto final da disciplina de Introdução a Técnicas de Programação, cujo objetivo é criar um programa para geração aleatória de terrenos em C.

## O que foi feito
- Modularização do programa
- Definição dos tipos de dados necessários  (typedef e structs)
- Geração da linha de contorno em um arranjo
- Leitura dos parâmetros de configuração (fator de deslocamento) em linha de comando
- Criação de uma imagem a partir do arranjo com a linha de contorno
- Alocação dinâmica da imagem gerada, com um tamanho dependente de uma valor fornecido em linha de comando (por exemplo: -s 257)

##  Como compilar  o projeto
- Clone o repositório usando 
``git clone https://github.com/Jardeu/geracao-de-terrenos.git``
- Abra o terminal e navegue até a pasta clonada e execute o seguinte comando ``gcc main.c functions.c ppmgenerator.c -o terreno -g -W``
- Depois execute o seguinte comando ``./terreno -d <deslocamento_maximo> -o <nome_da_imagem.ppm> -s <tamanho_da_imagem>``

## Autores
 - Johny Lúcio Teixeira da Costa
   - Definição dos tipos de dados
   - Geração da linha de contorno
   - Criação da imagem a partir da linha de contorno
 - José Jardeu Vicente da Silva
   - Modularização
   - Leitura dos parâmetros de configuração
   - Alocação dinâmica da imagem gerada
