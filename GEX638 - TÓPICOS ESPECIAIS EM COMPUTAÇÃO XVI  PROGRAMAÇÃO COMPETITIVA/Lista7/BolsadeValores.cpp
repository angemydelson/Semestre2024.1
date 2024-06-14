#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> precos(N);
    for (int i = 0; i < N; ++i) {
        cin >> precos[i];
    }

    // Inicializando os vetores dp
    vector<int> dp_compra(N, 0);
    vector<int> dp_venda(N, 0);

    // Comprando no primeiro dia
    dp_compra[0] = -precos[0] - C; 

    for (int i = 1; i < N; ++i) {
        dp_compra[i] = max(dp_compra[i - 1], dp_venda[i - 1] - precos[i] - C);
        dp_venda[i] = max(dp_venda[i - 1], dp_compra[i - 1] + precos[i]);
    }

    // O lucro máximo não pode ser negativo, então usamos max(0, dp_venda[N - 1])
    cout << max(0, dp_venda[N - 1]) << endl; 

    return 0;
}
