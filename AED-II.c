#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
//#include "/home/danton/Downloads/lista.h"
//#include "/home/danton/Downloads/fila.h"

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
char mover (char direction)
{
    direction=getch();
    return direction;
}
//////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    int op;
    char s;
    /*while(op!=2)
    {
        int op;
        menu(op);
        if(op==1)
        {
            //comeca o jogo
        }*/
    s=getch();
    if(s==37){printf("esquerda\n");}
    if(s==38){printf("cima\n");}
    if(s==39){printf("direita\n");}
    if(s==40){printf("baixo\n");}
    else{printf("nao e um cursor\n");}
    getch();
    };
