#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int matriz[20][20],i,j,x,y,v=8,t=0;
    char tab[20][20];
    srand((unsigned)time(NULL));//funçao para gerar numeros diferentes no rand

    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            matriz[i][j]=rand()%2;//sorteia numeros aleatorios para os barcos
            tab[i][j]='-';//monta o tabuleiro oculto
        }
    }
    printf("Bem Vindo ao Batalha Naval!!!\nAlphaVersion 1.0 By Isaccsz\n\n");

    while(v!=0 && t!=8){

        for(i=0;i<20;i++){
            for(j=0;j<20;j++){
                printf(" %c ",tab[i][j]);//mostra o tabuleiro do jogo
            }
            printf("\n");
        }

        //entrada de dados
        printf("Coordenada X: ");
        scanf("%d",&x);
        printf("Coordenada Y: ");
        scanf("%d",&y);
        system("cls");
        printf("\nExecutando disparo em [%d][%d]\n",x,y);

        //processamento de dados, e saida de dados
        if(matriz[x-1][y-1]==1){
            tab[x-1][y-1]='X';
            matriz[x-1][y-1]=2;
            t+=1;
            printf("Você acertou!!! Embarcações afundadas: %d\n",t);
            system("pause");
        }else if(matriz[x-1][y-1]==2){
            printf("Voce já disparou contra este local.\n");
            system("pause");
        }else if(matriz[x-1][y-1]==0){
            v-=1;
            tab[x-1][y-1]='*';
            matriz[x-1][y-1]=2;
            printf("Você errou!! %d chances restantes\n",v);
            system("pause");
        }

    }
    //resultado
    if(v==0){
        printf("Você perdeu!!!\nEncerrando o Game, obrigado por jogar <3\n");
    }else{
        printf("Você Ganhou!!!\nEncerrando o Game, obrigado por jogar <3\n");
    }

    return 0;
}
