#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 80

typedef struct arvore
{
    int info;
    struct arvore *esq;
    struct arvore *dir;
} arv;
arv *lerArq(arv *arvore,FILE *arq);
void imparvpre(arv *arvo);
void imparvpos(arv *arvo);
void imparvordem(arv *arvo);
void implargura(arv *arvo);
void opcaoimp(arv *arvo);
void impfolha(arv *arvore);
void sair(arv *arvore);
void vercheia(arv* arvore);
int contoco(arv *arvo,int x);
int altarv(arv *arvore);
int contno(arv *arvore);
int veriord(arv *arvore);
int main()
{
    int a,c;
    char nomeArq[MAX];
    arv *arvore=NULL;
    FILE *arq=NULL;
    do
    {
        c=0;
        printf("Digite (1) para ler um arquivo\n");
        printf("Digite (2) para imprimir a arvore\n");
        printf("Digite (3) para verificar se um elemento esta escrito na arvore\n");
        printf("Digite (4) para calcular a altura da arvore\n");
        printf("Digite (5) para contar o numero de ocorrencias de um elemento\n");
        printf("Digite (6) para imprimir as folhas\n");
        printf("Digite (7) para contar os nos internos\n");
        printf("Digite (8) para verificar se a arvore e cheia\n");
        printf("Digite (9) para verificar se a arvore esta ordenada\n");
        printf("Digite (0) para sair\n");
        scanf("%d",&a);
        if(a==1)
        {
            system("cls");
            printf("Digite o nome do arquivo:\n");
            setbuf(stdin,NULL);
            scanf("%80[^\n]",nomeArq);
            arq = fopen(nomeArq,"r");
            if (!arq)
            {
                printf("Erro ao abrir o arquivo");
                exit(EXIT_FAILURE);
            }
            arvore = lerArq(arvore,arq);
        }
        if(a==2)
        {
            system("cls");
            opcaoimp(arvore);
            system("pause");
        }
        if(a==3)
        {
            printf("Digite o valor a ser checado\n");
            int x;
            scanf("%d",&x);
            c = contoco(arvore,x);
            if(c>0)
            {
                printf("O elemento existe\n");
            }
            else
            {
                printf("O elemento n existe\n");
            }
            system("pause");
        }
        if(a==4)
        {
            c = altarv(arvore);
            printf("A altura da arvore e: %d\n",c);
            system("pause");
        }
        if(a==5)
        {
            printf("Digite o valor a ser checado\n");
            int x;
            scanf("%d",&x);
            c = contoco(arvore,x);
            printf("\nOcorrencias:%d\n",c);
            system("pause");
        }
        if(a==6)
        {
            printf("As folhas sao: ");
            impfolha(arvore);
            printf("\n");
            system("pause");
        }
        if(a==7)
        {
            c = contno(arvore);
            printf("O numero de nos internos da arvore e: %d\n",c);
            system("pause");
        }
        if(a==8)
        {
            vercheia(arvore);
            system("pause");
        }
        if(a==9)
        {
            c = veriord(arvore);
            printf("%d\n",c);
            if (c==0)
            {
                printf("A arvore esta ordenada\n");
            }
            else
            {
                printf("A arvore n esta ordenada\n");
            }
            system("pause");

        }
        if(a==0)
        {
            sair(arvore);
            printf("Desalocamento realizado com sucesso\n");
            system("pause");
        }
        system("cls");
    }
    while(a!=0);
    printf("Ate a proxima");
    return 0;
}

arv *lerArq(arv *arvore,FILE *arq)
{
    int val;
    fscanf(arq," %c",&val);
    fscanf(arq," %d",&val);
    if (val!=-1)
    {
        arvore = (arv*)malloc(sizeof(arv));
        if (!arq)
        {
            printf("Erro ao alocar memoria");
            exit(EXIT_FAILURE);
        }
        arvore->info = val;
        arvore->esq =lerArq(arvore->esq,arq);
        arvore->dir =lerArq(arvore->dir,arq);
        fscanf(arq," %c",&val);
        return arvore;
    }
    else
    {
        fscanf(arq," %c",&val);
        return NULL;
    }
}
void imparvpre(arv *arvo)
{
    if(arvo != NULL)
    {
        printf("%d\n", arvo->info);
        imparvpre(arvo->esq);
        imparvpre(arvo->dir);
    }
}

void imparvordem(arv *arvo)
{
    if(arvo != NULL)
    {
        imparvordem(arvo->esq);
        printf("%d\n", arvo->info);
        imparvordem(arvo->dir);
    }
}

void imparvpos(arv *arvo)
{
    if(arvo != NULL)
    {
        imparvpos(arvo->esq);
        imparvpos(arvo->dir);
        printf("%d\n", arvo->info);
    }
}
void opcaoimp(arv *arvo)
{
    int b;
    printf("Digite (1) para Pre-ordem\n");
    printf("Digite (2) para ordem\n");
    printf("Digite (3) para Pos-ordem\n");
    printf("Digite (4) para Largura\n");
    printf("Digite (5) para sair\n");
    setbuf(stdin,NULL);
    scanf("%d",&b);
    system("cls");
    while((b!=1) && (b!=3) && (b!=2) &(b!=4)&&(b!=5))
    {
        system("cls");
        printf("Digite (1) para Pre-ordem\n");
        printf("Digite (2) para ordem\n");
        printf("Digite (3) para Pos-ordem\n");
        printf("Digite (4) para Largura\n");
        printf("Digite (5) para sair\n");
        scanf("%d",&b);
        system("cls");

    }

    if(b==1)
    {
        imparvpre(arvo);
    }
    if(b==2)
    {
        imparvordem(arvo);
    }
    if(b==3)
    {
        imparvpos(arvo);
    }
    if(b==4)
    {
        implargura(arvo);
    }
    if(b == 5)
    {
        sair(arvo);
    }
}
int contoco(arv *arvo,int x)
{
    int a=0;
    if(arvo != NULL)
    {

        if(x==arvo->info)
        {
            a = 1 +contoco(arvo->esq,x)+contoco(arvo->dir,x);
            return a;
        }
        else
        {
            a = contoco(arvo->esq,x)+contoco(arvo->dir,x);
            return a;
        }
    }
}
int altarv(arv *arvore)
{
    int dir,esq;
    if(!arvore)
    {
        return 0;
    }
    else
    {
        dir = altarv(arvore->dir);
        esq = altarv(arvore->esq);
        if(dir>esq)
        {
            return dir +1;
        }
        else
        {
            return esq+1;
        }
    }
}
void impfolha(arv *arvore)
{
    if(arvore==NULL)
    {
        return;
    }
    if (arvore->dir == NULL && arvore->esq == NULL)
    {
        printf("%d\t",arvore->info);
    }
    else
    {
        impfolha(arvore->dir);
        impfolha(arvore->esq);
    }
}
int contno(arv *arvore)
{
    if (!arvore)
    {
        return 0;
    }
    else
    {

        return 1 + contno(arvore->dir) + contno(arvore->esq);

    }
}
void sair(arv *arvore)
{
    arv *tempd,*tempe;
    if (arvore==NULL)
    {
        return;
    }
    else
    {
        tempd = arvore->dir;
        tempe = arvore->esq;
        free(arvore);
        sair(tempd);
        sair(tempe);
    }

}
void vercheia(arv* arvore)
{
    int a = contno(arvore);
    int b = altarv(arvore);
    b = pow(2,b)-1;
    if (a == b)
    {
        printf("A arvore e cheia\n");
    }
    else
    {
        printf("A arvore n e cheia\n");
    }
}
int veriord(arv *arvore)
{
    int a = 0 ;
    if(arvore->dir == NULL || arvore->esq == NULL)
    {
        return 0;
    }
    else
    {
        if((arvore->dir->info) < (arvore->info) && (arvore->esq->info) >= (arvore->info))
        {
            a = veriord(arvore->dir)+ veriord(arvore->esq);
            return a;
        }
        else
        {

            a = 1 + veriord(arvore->dir)+veriord(arvore->esq);
            return a;
        }

    }
}
void implargura(arv *arvo)
{
    if(!arvo)
    {
    }
    else
    {
        printf("%d\t",arvo->info);
        implargura(arvo->esq);
        printf("\n");
        implargura(arvo->dir);
    }
}
