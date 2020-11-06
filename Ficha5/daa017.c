#include <stdio.h>

int main(int argc, char const *argv[]){
    int camadas;
    scanf("%d", &camadas);
    long long pedras[camadas][camadas];
    int deterioradas;
    scanf("%d", &deterioradas);

    
    for(int i = 0; i < camadas; i++){
        for(int j = 0; j < camadas; j++){
            pedras[i][j] = 0;
            if(i == camadas-1) pedras[i][j] = 1;
        }
    }

    for(int i = 0; i < deterioradas; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        pedras[camadas-x][y-1] = -1;
    }

    for(int i = camadas-2; i >= 0; i--){
        //printf("Entrou?\n");
        for(int j = 0; j <= i; j++){
            //printf("Talvez\n");
            if(pedras[i][j] != -1){
                //esquerda
                if(pedras[i+1][j] != -1){
                   //printf("42\n");
                   pedras[i][j] += pedras[i+1][j];
                }
                //direita
                if(pedras[i+1][j+1] != -1){
                    //printf("69\n");
                    pedras[i][j] += pedras[i+1][j+1];
                }
            }
        }
    }

    //for(int i = 0; i < camadas; i++){
    //    for(int j = 0; j < camadas; j++){
    //        if(j <= i){
    //            printf("i,j: %d %d -> %lld   ", i+1, j+1, pedras[i][j]);
    //        }
    //    }
    //    printf("\n");
    //}

    if(pedras[0][0] == -1){
        printf("0\n");
    }else{
        printf("%lld\n", pedras[0][0]);
    }
}
