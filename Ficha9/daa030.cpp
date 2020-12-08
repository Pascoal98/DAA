// Exemplo de pesquisa em largura (BFS) num grafo nao dirigido
// (codigo adaptado do codigo em Java feito na teorica)
// (inclui calculo de distancias)
// (esta versao nao tem "garbage collection", ou seja, nao limpa no final a memoria)
// (compilar com g++)

#include <cstdio>
#include <list>

using namespace std; // Para incluir o namespace std

#define MAX 5000

typedef struct {
  list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
  int distance;   // Distancia do no origem da pesquisa
  int maxdist;     //Distancia maior naquele no
} Node;

typedef struct {
  int n;
  Node nodes[MAX];
} Graph;

void addLink(Graph *g, int a, int b) {
  g->nodes[a].adj.push_back(b);
  g->nodes[b].adj.push_back(a);
}

void bfs(Graph *g, int v) {
  list<int> q;
  for (int i=1; i<=g->n; i++) g->nodes[i].visited = false;
  
  q.push_back(v);
  g->nodes[v].visited  = 1;
  g->nodes[v].distance = 0;
  g->nodes[v].maxdist = 0;

  while (q.size() > 0) {
    int u = q.front(); q.pop_front();
    //printf("%d [dist=%d]\n", u, g->nodes[u].distance);
      for (auto w : g->nodes[u].adj)
	    if (!g->nodes[w].visited) {
	    q.push_back(w);
	    g->nodes[w].visited  = true;
	    g->nodes[w].distance = g->nodes[u].distance + 1;
        if(g->nodes[w].distance > g->nodes[v].maxdist) {
            g->nodes[v].maxdist = g->nodes[w].distance;
            //printf("%d -> %d\n",v,g->nodes[v].maxdist);
        } 	  
	}      
  }
}

int main() {
    int e, a, b;

    Graph *g = new Graph;
    scanf("%d", &g->n);
    scanf("%d", &e);
    for (int i=0; i<e; i++) {
        scanf("%d %d", &a, &b);
        addLink(g, a, b);
    }
  
    for (int i = 1; i <= g->n ; i++) {       
        bfs(g, i);
    }

    int max = 0;
    int min = 100;            //valor minimo possivel

    for(int i = 1; i <= g->n ; i++){
        if(g->nodes[i].maxdist > max){
            max = g->nodes[i].maxdist;
        }
        if(g->nodes[i].maxdist < min){
            min = g->nodes[i].maxdist;
        }
    }
    printf("%d\n",max);
    printf("%d\n",min);
    int count = 0;

    for(int i = 1; i <= g->n ; i++){
        if(g->nodes[i].maxdist == min && count == 0){
            printf("%d",i);
            count++;
        } else if(g->nodes[i].maxdist == min){
                    printf(" %d",i);
        }
    }
    putchar('\n');
    count = 0;
    for(int i = 1; i <= g->n ; i++){
        if(g->nodes[i].maxdist == max && count == 0){
            printf("%d",i);
            count++;
        } else if(g->nodes[i].maxdist == max){
                    printf(" %d",i);
        }
    }
    putchar('\n');

  return 0;
}
