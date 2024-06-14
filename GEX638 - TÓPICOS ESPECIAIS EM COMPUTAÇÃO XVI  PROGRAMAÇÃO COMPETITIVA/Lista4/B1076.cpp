#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

// Função para realizar a DFS modificada que conta os movimentos
int dfsContaMovimentos(vector<vector<int>>& adj, int inicio) {
    int movimentos = 0;
    vector<vector<bool>> visitado(adj.size(), vector<bool>(adj.size(), false));
    stack<tuple<int, int>> pilha;
    
    pilha.push({inicio, -1});
    while (!pilha.empty()) {
        auto [nodo, pai] = pilha.top();
        pilha.pop();
        for (int vizinho : adj[nodo]) {
            if (!visitado[nodo][vizinho]) {
                movimentos++;
                visitado[nodo][vizinho] = visitado[vizinho][nodo] = true;
                pilha.push({vizinho, nodo});
            }
        }
    }
    
    return movimentos;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, V, A;
        cin >> N >> V >> A;
        
        vector<vector<int>> adj(V);
        for (int i = 0; i < A; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Contar os movimentos usando DFS
        int total_movimentos = dfsContaMovimentos(adj, N) * 2;
        
        cout << total_movimentos << endl;
    }
    
    return 0;
}
