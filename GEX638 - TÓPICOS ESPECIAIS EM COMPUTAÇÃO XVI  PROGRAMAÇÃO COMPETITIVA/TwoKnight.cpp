#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; ++k) {
        // Total de combinações para colocar dois cavaleiros no tabuleiro k*k
        long long totalCombinacoes = (long long)k * k * (k * k - 1) / 2;
        // Subtraindo as posições onde os cavaleiros podem se atacar
        // Cada cavaleiro tem 2 formas de atacar em 4 direções, totalizando 8 maneiras.
        // As posições dos cantos são contadas duas vezes, por isso a multiplicação por 4.
        long long ataques = 4 * (k - 1) * (k - 2);
        cout << totalCombinacoes - ataques << endl;
    }

    return 0;
}
