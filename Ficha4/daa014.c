#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int days;
    int fee;
    int indice;
    float ratio;
}Shoes;

int order(const void *a, const void *b){
    Shoes *ord1 = (Shoes *)a;
    Shoes *ord2 = (Shoes *)b;

    if(ord1->ratio < ord2->ratio) return +1;
    if(ord1->ratio > ord2->ratio) return -1;
    if(ord1->ratio == ord2->ratio){
        if(ord1->indice < ord2->indice) return -1;
        else return +1;
    }
    return 0;
}

int main(int argc, char const *argv[]){
    int orders;
    scanf("%d",&orders);

    Shoes s[orders+1];

    s[0].days = 0;
    s[0].fee = 0;
    //printf("Encomenda 0 :%d %d\n",s[0].days,s[0].fee);
    for (int i = 1;i <= orders;i++){
        scanf("%d %d",&s[i].days,&s[i].fee);
        s[i].indice = i;
        s[i].ratio = (float)s[i].fee / (float)s[i].days;
        //printf("Encomenda %d :%d %d %d %.1f\n",i,s[i].days,s[i].fee,s[i].indice,s[i].ratio);
    }   

    qsort(s,orders+1,sizeof(Shoes),order);

    for(int i = 0; i < orders-1; i++){
        printf("%d ",s[i].indice);
    }
    printf("%d\n",s[orders-1].indice);
    //printf("\n");
    return 0;
}
