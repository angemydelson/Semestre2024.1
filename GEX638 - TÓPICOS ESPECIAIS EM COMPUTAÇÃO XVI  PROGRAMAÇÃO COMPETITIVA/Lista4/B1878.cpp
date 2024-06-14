#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>  // Incluindo o cabeçalho para std::function

using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<int> coeficientes(N);
        for (int i = 0; i < N; ++i) {
            cin >> coeficientes[i];
        }

        unordered_set<long long> vistos;
        vector<int> classificacao(N);
        
        // Definindo a função recursiva para gerar classificações
        function<bool(int)> geraClassificacoes = [&](int pos) {
            if (pos == N) {
                long long valor = 0;
                for (int i = 0; i < N; ++i) {
                    valor += classificacao[i] * coeficientes[i];
                }
                if (vistos.find(valor) != vistos.end()) {
                    return false;
                }
                vistos.insert(valor);
                return true;
            }
            for (int i = 1; i <= M; ++i) {
                classificacao[pos] = i;
                if (!geraClassificacoes(pos + 1)) {
                    return false;
                }
            }
            return true;
        };

        if (geraClassificacoes(0)) {
            cout << "Lucky Denis!" << endl;
        } else {
            cout << "Try again later, Denis..." << endl;
        }
    }
    return 0;
}
