#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(int s, vector<vector<int>>& adj, vector<int>& time) {
    queue<int> fila;
    fila.push(s);
    time[s] = 1; // Começamos com a equipe 1

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();

        for (int vizinho : adj[atual]) {
            if (time[vizinho] == 0) { // Se não foi visitado
                time[vizinho] = 3 - time[atual]; // Alterna entre 1 e 2
                fila.push(vizinho);
            } else if (time[vizinho] == time[atual]) {
                return false; // Encontramos um conflito
            }
        }
    }

    return true;
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

    vector<int> time(n + 1, 0); // 0 = não visitado, 1 = equipe 1, 2 = equipe 2

    for (int i = 1; i <= n; ++i) {
        if (time[i] == 0) {
            if (!bfs(i, adj, time)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << time[i] << " ";
    }
    cout << endl;

    return 0;
}
