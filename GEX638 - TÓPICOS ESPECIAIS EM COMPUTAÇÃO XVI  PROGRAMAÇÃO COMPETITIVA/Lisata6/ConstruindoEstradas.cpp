#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int cidade, vector<vector<int>>& adj, vector<bool>& visitado) {
    queue<int> fila;
    fila.push(cidade);
    visitado[cidade] = true;

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        for (int vizinho : adj[atual]) {
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                fila.push(vizinho);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visitado(n + 1, false);
    vector<int> componentes;

    for (int i = 1; i <= n; ++i) {
        if (!visitado[i]) {
            componentes.push_back(i);
            bfs(i, adj, visitado);
        }
    }

    int k = componentes.size() - 1;
    cout << k << endl;
    for (int i = 1; i < componentes.size(); ++i) {
        cout << componentes[i - 1] << " " << componentes[i] << endl;
    }

    return 0;
}
