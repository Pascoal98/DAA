#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ADN 10000

typedef struct{
    char letra;
    int frequencia;
    int posicao;
}Letra;

int compareChar(const void *a, const void *b){
  Letra *l1 = (Letra *)a;
  Letra *l2 = (Letra *)b;
  if(l1->frequencia < l2->frequencia) return -1;
  if(l1->frequencia > l2->frequencia) return +1;

  return l1->posicao < l2->posicao?1:-1;  
}

int main(int argc, char const *argv[]){
    Letra abc[26];
    char c;
    int pog = 0;
    for(int i = 0; i < 26; i++){
        abc[i].letra = 'A' + i;
        abc[i].frequencia = 0;
        abc[i].posicao = -1; 
    }

    while ((c = getchar()) != '\n' && c != EOF){
        abc[c-'A'].frequencia += 1;
        if(abc[c-'A'].posicao == -1){
            abc[c-'A'].posicao = pog;
        }
        pog++;
    }
    
    qsort(abc,26,sizeof(Letra),compareChar);

    for (int i = 25; i >= 0; i--){ 
        if(abc[i].frequencia >= 1){  
            printf("%c %d\n",abc[i].letra,abc[i].frequencia);
        }
    }
    
    return 0;
}