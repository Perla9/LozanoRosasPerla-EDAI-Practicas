#include <stdio.h>
void menu(char tab[8][8]){
    int i,j,x,y;
    char opc;
    while(1)
    {
        printf("Escoga la opcion\n");
        printf("1)Caballo\n");
        printf("2)Afil\n");
        printf("3)Torre\n");
        printf("4)Reina\n");
        printf("5)Rey\n");
        printf("6)Salir\n");
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            {
                printf("Posicion del caballo\n");
                printf("Ingrese valor x:"); 
                scanf("%i",&x);
                printf("Ingrese valor y:"); 
                scanf("%i",&y);
                llenarTab(tab);
                caballo(tab,x-1,y-1);
                mostrarTab(tab);
                return 0;
                break;
            }
        case 2:
            {
                printf("Posicion del alfil\n");
                printf("Ingrese valor x:"); 
                scanf("%i",&x);
                printf("Ingrese valor y:");
                scanf("%i",&y);
                llenarTab(tab);
                alfil(tab,x-1,y-1);
                mostrarTab(tab);
                break;
            }
        case 3:
            {
                printf("Posicion de la Torre\n");
                printf("Ingrese valor x:"); 
                scanf("%i",&x);
                printf("Ingrese valor y:");
                scanf("%i",&y);
                llenarTab(tab);
                torre(tab,x-1,y-1);
                mostrarTab(tab);
                break;

            }
        case 4:
            {
                printf("Posicion de la Reyna\n");
                printf("Ingrese valor x:"); 
                scanf("%i",&x);
                printf("Ingrese valor y:");
                scanf("%i",&y);
                llenarTab(tab);
                reina(tab,x-1,y-1);
                mostrarTab(tab);
            }
        case 5:
            {
                printf("Posicion del rey\n");
                printf("Ingrese la posicion para x\n");
                scanf("%i",&x);
                printf("Ingrese la posicion para y\n");
                scanf("%i",&y);
                llenarTab(tab);
                rey(tab,x-1,y-1);
                mostrarTab(tab);
                break;
            }
        case 6:
            {
                return 0;
            }
        default:
        {
            printf("Opcion invalida");
        }
        }
    }
    return 0;

}
int main()
{
    char tab[8][8];
    menu(tab);
    return 0;
}
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
struct caballo{
    int x,y;
    char tab[8][8];
};

void caballo(char tab[8][8],int x,int y){
        int i,j;
        for(i=y-2;i<=y+2;i+=4){//Eje vertical
            j=x-1;
            if(i>=0 && i<=7 && j>=0 && j<=7)
            {tab[i][j]='X';}
            j=x+1;
            if(i>=0 && i<=7 && j>=0 && j<=7)
            {tab[i][j]='X';}
            }
        for(j=x-2;j<=x+2;j+=4){//Eje horizontal
            i=y-1;
            if(i>=0 && i<=7 && j>=0 && j<=7)
            {tab[i][j]='X';}
            i=y+1;
            if(i>=0 && i<=7 && j>=0 && j<=7)
            {tab[i][j]='X';}
            }
        i=y; //Valor del caballo
        j=x;
        tab[i][j]='C';

}    

struct alfil{
    int x,y;
    char tab[8][8];
};
void alfil(char tab[8][8],int x,int y){
    int i,j;
    i=y;   //Diagonal principal
    j=x;
    while(i>=0 && j>=0){
        tab[i][j]='X';
        i--;
        j--;
    }
    i=y;
    j=x;
    while(i<=7 && j<=7) {
        tab[i][j]='X';
        i++;
        j++;
    }
    i=y;     //diagonal secundaria
    j=x;
    while(i<=7 && j>=0){
        tab[i][j]='X';
        i++;
        j--;
    }
    i=y;
    j=x;
    while(i>=0 && j<=7) {
        tab[i][j]='X';
        i--;
        j++;
    }
    i=y; //valor alfil
    j=x;
    tab[i][j]='A';
}
struct torre{
    int x,y;
    char tab[8][8];
};
void torre(char tab[8][8],int x,int y){
    int i,j;
    j=x; //Eje vertical
    for(i=0;i<8;i++){
        tab[i][j]='X';
    }
    i=y;//Eje horizontal
    for(j=0;j<8;j++){
        tab[i][j]='X';
    }
    i=y;    //Valor de la torre
    j=x;
    tab[i][j]='T';
}
struct reina{
    int x,y;
    char tab[8][8];
};
void reina(char tab[8][8],int x,int y)
{
        int i,j;
    j=x; //Eje vertical
    for(i=0;i<8;i++){
        tab[i][j]='X';
    }
    i=y; //Eje horizontal
    for(j=0;j<8;j++){
        tab[i][j]='X';
    }
    i=y;//Diagnoal principal
    j=x;
    while(i>=0 && j>=0){
        tab[i][j]='X';
        i--;
        j--;
    }
    i=y;
    j=x;
    while(i<=7 && j<=7) {
        tab[i][j]='X';
        i++;
        j++;
    }
    i=y; //Diagnoal principal
    j=x;
    while(i<=7 && j>=0){
        tab[i][j]='X';
        i++;
        j--;
    }
    i=y;
    j=x;
    while(i>=0 && j<=7){
        tab[i][j]='X';
        i--;
        j++;
    }
    i=y; //Valor de la reina
    j=x;
    tab[i][j]='Q';
}
struct rey{
    int x,y;
    char tab[8][8];
};
void rey(char tab[8][8],int x,int y)
{
    int i,j;
    j=x; //Eje vertical
    for(i=y-1;i<=y+1;i++){
        if(i>=0 && i<=7 && j>=0 && j<=8)
        {tab[i][j]='X';}
    }
    i=y; //Eje horizontal
    for(j=x-1;j<x+2;j++){
        if(i>=0 && i<=7 && j>=0 && j<=8)
        {tab[i][j]='X';}
    }
    i=y-1; //Diagnoal principal
    j=x-1;
    if(i>=0 && i<=7 && j>=0 && j<=8)
    {tab[i][j]='X';}
    i=y+1;
    j=x+1;
    if(i>=0 && i<=7 && j>=0 && j<=8)
    {tab[i][j]='X';}
    i=y+1;    //diagonal secundaria
    j=x-1;
    if(i>=0 && i<=7 && j>=0 && j<=8)
    {tab[i][j]='X';}
    i=y-1;
    j=x+1;
    if(i>=0 && i<=7 && j>=0 && j<=8)
    {tab[i][j]='X';}
    i=y; //Valor del rey
    j=x;
    tab[i][j]='R';
}
