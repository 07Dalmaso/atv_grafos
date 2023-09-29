#include <stdio.h>
#include <stdbool.h>

#define MAXN 100000

int graph[MAXN + 1][MAXN + 1];
bool visited[MAXN + 1];

int dfs(int u, int N) {
    visited[u] = true;
    int components = 1;
    
    for (int v = 1; v <= N; v++) {
        if (!visited[v] && graph[u][v] == 1) {
            components += dfs(v, N);
        }
    }
    
    return components;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        
        // Inicialização
        for (int i = 1; i <= N; i++) {
            visited[i] = false;
            for (int j = 1; j <= N; j++) {
                graph[i][j] = 0;
            }
        }
        
        // Leitura das amizades
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        
        long long max_routes = 0;
        long long ways_to_choose_captains = 1;
        
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                int components = dfs(i, N);
                max_routes++;
                ways_to_choose_captains *= components;
                ways_to_choose_captains %= 1000000007;
            }
        }
        
        printf("Resposta: %lld %lld\n", max_routes, ways_to_choose_captains);
    }
    
    return 0;
}
