#include <stdio.h>

void menu(char tab[8][8])
{
    int i,j,x,y;
    printf("Posicion de la Torre\n");
    printf("Ingrese valor x:"); 
    scanf("%i",&x);
    printf("Ingrese valor y:");
    scanf("%i",&y);
    llenarTab(tab);
    torre(tab,x-1,y-1);
    mostrarTab(tab);
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
            if((i+j)%2 == 0){
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

void torre(char tab[8][8],int x,int y){
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
     //Valor de la reina
    i=y;
    j=x;
    tab[i][j]='T';
}