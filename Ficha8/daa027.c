#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int node,edge,color;
bool adj[MAX][MAX];
int colored[MAX];

bool coloring(int x, int color) {
    int newColor;
    if(color == 1) {
        newColor = 2;
    } else {
        newColor = 1;
    }
    if(colored[x] != 0) {
        if(colored[x] != newColor) {
            return false;
        }
        return true;
    }

    if(colored[x] == 0) {
        colored[x] = newColor;
        for(int i = 0; i < node; i++) {
            if(adj[x][i]) {
                if(!coloring(i,newColor)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n ; i++) {
        scanf("%d",&node);
        scanf("%d",&edge);

        for(int j = 0; j < edge; j++) {
            int x;
            scanf("%d",&x);
            int y;
            scanf("%d",&y); 
            x--;
            y--;
            adj[x][y] = true;
            adj[y][x] = true;
        }
        bool answer = coloring(0,1);
        if(answer) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
        for(int k = 0; k < MAX; k++){
            colored[k] = 0;
        }
        for(int l = 0; l < MAX; l++){
            for(int z = 0; z < MAX; z++){
                adj[l][z] = false;
            }
        }
    }
    return 0;
}
