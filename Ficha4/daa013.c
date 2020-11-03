#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int first;
    int last;
}Segmentos;

int ordenar(const void *a, const void *b){
    Segmentos *num1 = (Segmentos *)a;
    Segmentos *num2 = (Segmentos *)b;

    if(num1->first == num2->first && num1->last > num2->last) return -1;
    if(num1->first == num2->first && num1->last < num2->last) return +1;
    if(num1->first < num2->first) return -1;
    if(num1->first > num2->first) return +1;
    if(num1->last < num2->last) return +1;

    return -1;
}

int greedySearch(int t,Segmentos s[],int n){
    int currentT = 0;
    int finalT = 0;

    for(int i = 0; i < n;i++){
        int aux = currentT;
        for(int j = i;s[j].first <=aux;j++){
            if(currentT >= t) break;

            if(s[j].last > currentT) currentT = s[j].last;
        }
        if(aux != currentT) finalT++;

        if(currentT >= t) break;
    }
    return finalT;
}

int main(int argc, char const *argv[]){
    int tSegmento;
    int n;
    scanf("%d",&tSegmento);
    scanf("%d",&n);
    Segmentos s[n];
    for(int i = 0; i < n;i++){
        scanf("%d %d",&s[i].first,&s[i].last);
    }

    qsort(s,n,sizeof(Segmentos),ordenar);

    /*for(int i = 0; i < n; i++){
        printf("Segmento %d : %d %d\n",i,s[i].first,s[i].last);
    }
    */
    printf("%d\n",greedySearch(tSegmento,s,n));

    return 0;
}
