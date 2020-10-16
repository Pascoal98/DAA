#include <stdio.h>

void diff(int a, int b, int *e){
    int diff = e[b]-e[a-1];
    printf("%d\n",diff);
}

int main(int argc, char const *argv[])
{
    int baku,energy;
    scanf("%d\n",&baku);
    int nbaku[baku], energysum[baku];
    nbaku[0] = 0;
    for(int i = 1; i <= baku; i++){
        scanf("%d ",&energy);
        nbaku[i] = energy;
    }
    energysum[0] = 0;
    for (int j = 1; j<=baku; j++){
        energysum[j] = nbaku[j] + energysum[j-1];
    }
    int a,b,casos;
    scanf("%d\n",&casos);
    for (int z = 0; z < casos; z++){
        scanf("%d %d\n",&a,&b);
        diff(a,b,energysum);
    }
    
    return 0;
}
