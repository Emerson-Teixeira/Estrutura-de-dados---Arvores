#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main()
{
    char nomeArq[80];
    int c,a;
    arv x;
    FILE *arq;
    while (c!=0){
       printf("Digite (1) para ler o arquivo");
       printf("Digite (2) para inserir");
       printf("Digite (3) para remover");
       printf("Digite (4) para Imprimir largura");
       printf("Digite (5) para Verificar existencia");
       printf("Digite (0) para sair");
       scanf("%d",&c);
       system("cls");
       if (c==1){
        printf("Digite o nome do arquivo");
        scanf("%80[^\n]",nomeArq);
        arq = fopen(nomeArq,"r");
        if(!arq){
            printf("Nao Foi Possivel Abrir o Arquivo");
            exit(EXIT_FAILURE);
        }
        //fun�ao de ler arq
       }
       if (c==2){
        printf("Digite o numero a ser inserido");
        scanf("%d",&a)
        //fun�ao de inserir
       }
       if (c==3){
        printf("Digite o valor a ser removido");
        scanf("%d",&a);
        //fun�ao de remover
       }
       if (c==4){
        //fun�ao largura
       }
       if (c==5){
        printf("Digite o valor a ser checado")
        scanf("%d",&a);
        //fun�ao checar
       }
       if (c==0){
        //fun�ao sair
       }
       system("pause");
       system("cls");
    }
}
