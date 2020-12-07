#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define FILL '#'

int n;              // Numero de nos do grafo
int rows;           //Numero de linhas
int cols;           //Numero de colunas
char adj[MAX][MAX];       // Matriz de adjacencias
bool visited[MAX][MAX];   // Que nos ja foram visitados?



int dfs(int r, int c) {
    //printf("dfs(%d,%d)\n",r,c);
    if(r < 0 || r >= rows || c < 0 || c >= cols) return 0;
    if(visited[r][c] || adj[r][c] != FILL) return 0;
    if(adj[r][c] == FILL) {
        visited[r][c] = true;
        return 1 + dfs(r+1,c-1) + dfs(r+1,c) + dfs(r+1,c+1) + dfs(r,c-1) + dfs(r,c+1) + dfs(r-1,c-1) + dfs(r-1,c) + dfs(r-1,c+1);
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    
    int n;
    scanf("%d",&n);

    for(int i = 0; i < n;i++) {
        int count = 0, max = 0;
        scanf("%d %d",&rows,&cols);
    
        for(int i = 0; i < rows; i++){
            scanf("%s",adj[i]);
        }

        /*for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++)
                printf("%c",adj[i][j]);
            putchar('\n');
        }*/

        for(int j = 0; j < rows; j++) {
            for(int k = 0; k < cols; k++) {
                if(adj[j][k] == FILL && !visited[j][k]) {
                    count = dfs(j,k);
                    if(count > max) {
                        max = count;
                    }
                }
            }
        }
        printf("%d\n",max);
        for(int j = 0; j < rows; j++) {
            for(int k = 0; k < cols; k++) 
            visited[j][k] = false;
        }
    }
    return 0;
}
