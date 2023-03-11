#include <stdio.h>
void llenarTab(char tab[8][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if((i+j)%2 == 0)
            {
                tab[i][j]=219;
            }
            else
            {
                tab[i][j]=' ';
            }
        }
    }
}

void mostrarTab(char tab[8][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        printf("\n");
        for(j=0;j<8;j++)
        {
            printf("%c",tab[i][j]);
        }
    }
}

void rey(char tab[8][8],int x,int y)
{
    int i,j;
    //Eje vertical
    j=x;
    for(i=y-1;i<=y+1;i++)
    {
        if(i>=0 && i<=7 && j>=0 && j<=8)
        {tab[i][j]='X';}
    }
    //Eje horizontal
    i=y;
    for(j=x-1;j<x+2;j++)
    {
        if(i>=0 && i<=7 && j>=0 && j<=8)
        {tab[i][j]='X';}
    }
    //Diagnoal principal
    i=y-1;
    j=x-1;
    if(i>=0 && i<=7 && j>=0 && j<=8)
    {tab[i][j]='X';}

    i=y+1;
    j=x+1;
    if(i>=0 && i<=7 && j>=0 && j<=8)
    {tab[i][j]='X';}
    //diagonal secundaria
    i=y+1;
    j=x-1;
    if(i>=0 && i<=7 && j>=0 && j<=8)
    {tab[i][j]='X';}

    i=y-1;
    j=x+1;
    if(i>=0 && i<=7 && j>=0 && j<=8)
    {tab[i][j]='X';}
    //Valor del rey
    i=y;
    j=x;
    tab[i][j]='R';
}

void reina(char tab[8][8],int x,int y)
{
        int i,j;
    //Eje vertical
    j=x;
    for(i=0;i<8;i++)
    {
        tab[i][j]='X';
    }
    //Eje horizontal
    i=y;
    for(j=0;j<8;j++)
    {
        tab[i][j]='X';
    }
    //Diagnoal principal
    i=y;
    j=x;
    while(i>=0 && j>=0)
    {
        tab[i][j]='X';
        i--;
        j--;
    }

    i=y;
    j=x;
    while(i<=7 && j<=7)
    {
        tab[i][j]='X';
        i++;
        j++;
    }
    //diagonal secundaria
    i=y;
    j=x;
    while(i<=7 && j>=0)
    {
        tab[i][j]='X';
        i++;
        j--;
    }

    i=y;
    j=x;
    while(i>=0 && j<=7)
    {
        tab[i][j]='X';
        i--;
        j++;
    }
    //Valor de la reina
    i=y;
    j=x;
    tab[i][j]='Q';
}

void menu(char tab[8][8])
{
    int i,j,x,y;
    char opc;
    while(1)
    {
        printf("Escoga la opcion");
        printf("Reyna(1), Rey(2) o Salir(3):");
        scanf("%d",&opc);
        switch(opc)
        {
        case '1':
            {
                printf("Posicion de la Reyna\n");
                printf("Ingrese valor x:"); 
                scanf("%i",x);
                printf("Ingrese valor y:");
                scanf("%i",y);
                llenarTab(tab);
                reina(tab,x-1,y-1);
                mostrarTab(tab);
                break;
            }
        case '2':
            {
                printf("Posicion del rey\n");
                printf("Ingrese la posicion para x\n");
                scanf("%i",x);
                printf("Ingrese la posicion para y\n");
                scanf("%i",y);
                llenarTab(tab);
                rey(tab,x-1,y-1);
                mostrarTab(tab);
                break;
            }
        case '3':
            {
                break;
            }
        default:
            {
                system("CLS");
                printf("Opcion invalida");
            }
        }
    }

}

int main()
{
    char tab[8][8];
    menu(tab);
    return 0;
}