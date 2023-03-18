
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


void caballo(char tab[8][8],int x,int y)
{
    int i,j;
    //Eje vertical
    for(i=y-2;i<=y+2;i+=4)
    {
        j=x-1;
        if(i>=0 && i<=7 && j>=0 && j<=7)
        {tab[i][j]='X';}
        j=x+1;
        if(i>=0 && i<=7 && j>=0 && j<=7)
        {tab[i][j]='X';}
    }
    //Eje horizontal
    for(j=x-2;j<=x+2;j+=4)
    {
        i=y-1;
        if(i>=0 && i<=7 && j>=0 && j<=7)
        {tab[i][j]='X';}
        i=y+1;
        if(i>=0 && i<=7 && j>=0 && j<=7)
        {tab[i][j]='X';}
    }
    //Valor del caballo
    i=y;
    j=x;
    tab[i][j]='C';

}

void menu(char tab[8][8])
{
    int i,j,x,y;

    printf("Posicion del caballo");
    printf("Ingrese valor x:"); 
    scanf("%i",&x);
    printf("Ingrese valor y:"); 
    scanf("%i",&y);
    llenarTab(tab);
    caballo(tab,x-1,y-1);
    mostrarTab(tab);
    return 0;
}

int main()
{
    char tab[8][8];
    menu(tab);
    return 0;
}