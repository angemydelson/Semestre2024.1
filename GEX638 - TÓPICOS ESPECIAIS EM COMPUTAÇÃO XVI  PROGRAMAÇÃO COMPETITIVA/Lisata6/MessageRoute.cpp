#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // Lista de adjacência para armazenar as conexões
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> distancia(n + 1, -1); // Vetor para armazenar a distância de cada nó a partir do nó 1
    vector<int> anterior(n + 1, -1); // Vetor para armazenar o nó anterior no caminho

    queue<int> fila;
    fila.push(1);
    distancia[1] = 0;

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();

        for (int vizinho : adj[atual]) {
            if (distancia[vizinho] == -1) {
                distancia[vizinho] = distancia[atual] + 1;
                anterior[vizinho] = atual;
                fila.push(vizinho);
            }
        }
    }

    if (distancia[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << distancia[n] + 1 << endl;
        vector<int> caminho;
        for (int v = n; v != -1; v = anterior[v]) {
            caminho.push_back(v);
        }
        reverse(caminho.begin(), caminho.end());
        for (int v : caminho) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
