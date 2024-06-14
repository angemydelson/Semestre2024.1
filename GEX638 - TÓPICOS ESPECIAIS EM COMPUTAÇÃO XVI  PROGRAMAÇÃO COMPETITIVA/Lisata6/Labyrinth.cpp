#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm> 

using namespace std;

struct Ponto {
    int x, y;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> labirinto(n, vector<char>(m));
    Ponto inicio, fim;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> labirinto[i][j];
            if (labirinto[i][j] == 'A') {
                inicio = {i, j};
            }
            if (labirinto[i][j] == 'B') {
                fim = {i, j};
            }
        }
    }

    vector<vector<bool>> visitado(n, vector<bool>(m, false));
    vector<vector<Ponto>> anterior(n, vector<Ponto>(m, {-1, -1}));
    vector<vector<char>> direcao(n, vector<char>(m));

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    char mov[] = {'L', 'R', 'U', 'D'};

    queue<Ponto> fila;
    fila.push(inicio);
    visitado[inicio.x][inicio.y] = true;

    bool caminho_encontrado = false;

    while (!fila.empty()) {
        Ponto atual = fila.front();
        fila.pop();

        if (atual.x == fim.x && atual.y == fim.y) {
            caminho_encontrado = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = atual.x + dx[i];
            int ny = atual.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && labirinto[nx][ny] != '#' && !visitado[nx][ny]) {
                fila.push({nx, ny});
                visitado[nx][ny] = true;
                anterior[nx][ny] = atual;
                direcao[nx][ny] = mov[i];
            }
        }
    }

    if (!caminho_encontrado) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<char> caminho;
        Ponto atual = fim;
        while (atual.x != inicio.x || atual.y != inicio.y) {
            caminho.push_back(direcao[atual.x][atual.y]);
            Ponto prev = anterior[atual.x][atual.y];
            atual = prev;
        }
        reverse(caminho.begin(), caminho.end());
        cout << caminho.size() << endl;
        for (char c : caminho) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
