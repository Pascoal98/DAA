#include <stdio.h>
#include <stdlib.h>

int comp (const void * elem1, const void * elem2){
    int first = *((int*)elem1);
    int second = *((int*)elem2);
    if (first > second) return  1;
    if (first < second) return -1;
    return 0;
}

int binarySearch(int pares[],int min,int max,int jackpot){
    int mid = 0;
    while(min <= max){
        mid = min + (max-min)/2;
        if(jackpot <=pares[mid]){
            max = mid-1;
        }
        else{
            min = mid + 1;
        }
    }
    if(max == -1) return pares[0];

    if(abs(jackpot-pares[min]) < abs(jackpot-pares[max])) return pares[min];
    else if(abs(jackpot-pares[min]) == abs(jackpot-pares[max])){
        printf("%d ",pares[max]);
        return pares[min];
    }
    return pares[max];
}

int main(int argc, char const *argv[]){
    int nNumeros,nPerguntas,numero;

    scanf("%d",&nNumeros);
    int numeros[nNumeros];

    for(int i = 0; i < nNumeros;i++){
        scanf("%d",&numero);
        numeros[i] = numero;
    }
    scanf("%d",&nPerguntas);
    int q[nPerguntas];
    for (int i = 0; i < nPerguntas;i++){
        scanf("%d",&numero);
        q[i] = numero;
    }

    int soma = (nNumeros*(nNumeros-1))/2;
    int pares[soma];

    int z = 0;
    for(int i = 0; i < nNumeros;i++){
        for(int j = i+1;j <=nNumeros-1;j++){
            pares[z] = numeros[i] + numeros[j];
            z++;
        }
    }
    qsort(pares,soma,sizeof(int),comp);

    for(int i = 0; i < nPerguntas;i++){
        printf("%d\n",binarySearch(pares,0,soma-1,q[i]));
    }
    return 0;
}
