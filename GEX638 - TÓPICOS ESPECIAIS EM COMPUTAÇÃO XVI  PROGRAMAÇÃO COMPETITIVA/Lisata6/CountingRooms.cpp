#include <iostream>
#include <vector>

using namespace std;

// Função para realizar a busca em profundidade (DFS) e marcar todas as células conectadas como visitadas
void dfs(vector<vector<char>>& map, vector<vector<bool>>& visited, int x, int y) {
    int n = map.size();
    int m = map[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || map[x][y] == '#' || visited[x][y]) {
        return;
    }

    visited[x][y] = true;

    // Movimentos possíveis: esquerda, direita, cima, baixo
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    for (int i = 0; i < 4; ++i) {
        dfs(map, visited, x + dx[i], y + dy[i]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int roomCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '.' && !visited[i][j]) {
                dfs(map, visited, i, j);
                roomCount++;
            }
        }
    }

    cout << roomCount << endl;

    return 0;
}
