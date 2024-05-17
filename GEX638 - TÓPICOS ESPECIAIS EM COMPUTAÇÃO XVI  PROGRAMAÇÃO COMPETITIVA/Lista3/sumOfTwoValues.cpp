#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Desativa a sincronização com as funções de C stdio.
    cin.tie(NULL); // Desativa o flush automático do cout antes de cin.

    int tamanho, somaAlvo;
    cin >> tamanho >> somaAlvo;

    vector<int> numeros(tamanho);
    for (int i = 0; i < tamanho; i++) {
        cin >> numeros[i];
    }

    unordered_map<int, int> valorParaIndice;
    valorParaIndice.reserve(tamanho); // Reserva espaço para n elementos.

    for (int i = 0; i < tamanho; i++) {
        int complemento = somaAlvo - numeros[i];
        
        if (valorParaIndice.find(complemento) != valorParaIndice.end()) {
            cout << valorParaIndice[complemento] + 1 << " " << i + 1 << "\n"; // Usar '\n' ao invés de endl para evitar flush.
            return 0;
        }

        valorParaIndice[numeros[i]] = i;
    }

    cout << "IMPOSSIBLE" << "\n"; // Usar '\n' ao invés de endl para evitar flush.
    return 0;
}
