#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "/home/danton/Downloads/lista.h"
#include "/home/danton/Downloads/fila.h"

////////////////////////////////////////////////////////////////////////////////////////////
int menu(int option)
{
    while(option!=1 || option!=2)
    {
    system("clear");
    //no windows eh system("cls");
    printf("1-Comecar novo jogo\n2-Sair\n");
    scanf("%d",&option);
    };
return option;
}
//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    int op;
    while(op!=2)
    {
        int op;
        menu(op);
    };

}
