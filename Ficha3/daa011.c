#include <stdio.h>
#include <stdbool.h>

bool possivel(int valor,int dias,int distancias[],int ndist){
    int divs = 0;
    int soma = 0;
    for(int i = 0;i < ndist;i++){
        soma = soma + distancias[i];
        if(soma > valor){
            divs++;
            soma = 0;
            i--;
        }
        if(divs >= dias) return false;
    }
    return true;
}

int binarySearch(int distancias[],int min,int max,int dias,int ndist){
    while(min < max){
        int mid = min + (max-min)/2;

        if(possivel(mid,dias,distancias,ndist)){
            max = mid;
        }else{
            min = mid+1;
        }
    }
    return possivel(min,dias,distancias,ndist)?min:-1;
}

int main(int argc, char const *argv[]){
    int ndist;
    scanf("%d",&ndist);
    int distancias[ndist];
    int maxdist = 0;
    int distancia;
    for(int i = 0; i < ndist;i++){
        scanf("%d",&distancia);
        distancias[i] = distancia;
        maxdist += distancias[i];
    }
    int perguntas,dias;
    scanf("%d",&perguntas);
    for(int i = 0;i < perguntas;i++){
        scanf("%d",&dias);
        printf("%d\n",binarySearch(distancias,1,maxdist,dias,ndist));
    }
    return 0;
}
