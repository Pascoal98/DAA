#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[]){
    int moedas;
    scanf("%d", &moedas);
    int tipos[moedas];
    for(int i = 0; i < moedas; i++){
        int aux;
        scanf("%d", &aux);
        tipos[i] = aux;
    }

    int perguntas;
    int MAX = 0;
    scanf("%d", &perguntas);
    int quantidade[perguntas];
    for(int i = 0; i < perguntas; i++){
        int aux;
        scanf("%d", &aux);
        if(aux > MAX) MAX = aux;
        quantidade[i] = aux;
    }

    int aux[MAX+1];
    int primeira[MAX+1];
    aux[0] = 0;
    primeira[0] = 0;
    for(int i = 1; i < MAX+1; i++){
        aux[i] = 10001;
        primeira[i] = tipos[0];
        for(int j = 0 ; j < moedas; j++){
            if(tipos[j] <= i && 1 + aux[i-tipos[j]] < aux[i]){
                int used = false;
                aux[i] = 1 + aux[i-tipos[j]]; 
                if(!used){
                    primeira[i] = tipos[j];
                    used = true;
                } 
            }
        }
        //printf("aux[%d] = %d\n", i, aux[i]);
        //printf("primeira[%d] = %d\n", i, primeira[i]);
    }
    
    for(int i = 0; i < perguntas; i++){
        int perg = quantidade[i];
        printf("%d: [%d]", perg, aux[perg]);
        printf(" %d", primeira[perg]);
        while(perg != 0){
            perg -= primeira[perg];
            if(primeira[perg] != 0) printf(" %d", primeira[perg]);
        }
        printf("\n");
    }
}