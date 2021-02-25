// Exemplo de pesquisa em profundidade (DFS) num grafo nao dirigido

#include <stdio.h>
#include <stdbool.h>

#define MAX 26      // Maximo numero de nos

int n;              // Numero de nos do grafo
bool adj[MAX][MAX]; // Matriz de adjacencias
bool visited[MAX];  // Que nos ja foram visitados?
char str1[100];
char str2[100];

void setAdj(int ad) {
    int i = 0;
    size_t length = sizeof(str1) / sizeof(str1[0]);
    printf("%ld\n",length);
}

void dfs(int v) {
    visited[v] = true;
    for (int i=1; i<=n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i);
}

int main() {
    int n;
    scanf("%d",&n);
    char c;
    for (int i = 0; i < 26; i++) {
        visited[i] = true;
    }

    scanf("%s",&*str1);
    printf("%s\n",str1);
    for (int i = 1; i < n;i++){
        scanf("%s",&*str2);
        printf("%s\n",str2);
        setAdj(i);
    }

    return 0;
}