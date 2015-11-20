#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

setlocale(LC_ALL,"portuguese");
srand(time(NULL));

typedef struct TipoArvore {
int code;
char name[20],color[20];
float price,weight;
TipoArvore *dir,*esq;
};


int menu(int op){
printf("1-Inserir peça\n2-Pesquisar peça\n3-Exibir caminhamento pre-ordem\n4-Exibir caminhamento in-ordem\n5-Exibir pos-ordem\n");
printf("6-Exibir numero de peças da arvore\n7-Exibir o maior código de peças da árvore\n8 – Exibir o menor código de peças da árvore");
printf("9-Exibir o número de folhas da árvore\n10-Dado um código de peça, imprimir a altura e profundidade do nó correspondente. ");
printf("11-Dado um código de peça, imprimir em ordem crescente (somente códigos) todos os descendentes do nó que contém o código.");
printf("12-Sair");
scanf("%d",&op);
return op;
                }

TipoArvore insere(TipoArvore *p){
system("cls");
if(rand()%2==0){p->dir=(TipoArvore*)malloc(sizeof(TipoArvore)); p=p->dir;}
else{p->esq=(TipoArvore*)malloc(sizeof(TipoArvore)); p=p->esq;}
printf("Insira o código da peça:");scanf("%d",*(p->code));
printf("Insira o nome da peça:");gets(*(p->name));fflush(stdin);
printf("Insira a cor da peça:");gets(*(p->color));fflush(stdin);
printf("Insira o preço da peça:");scanf("%.2f",*(p->price));
printf("Insira o peso da peça:");scanf("%.2f",*(p->weight));
getc();
}

TipoArvore procura(TipoArvore *p){
system("cls");
int search;
printf("Digite o codigo da peça que deseja localizar:")
scanf("%d",&search);
while(search!=p->code){

                      }
}

int main()
{
    int option;
    do {
    menu(option);
    switch(option)
    case 12:
    return 0;
    default:
    printf("Opção inválida");
    }while(option!=12);
    return 0;
}
