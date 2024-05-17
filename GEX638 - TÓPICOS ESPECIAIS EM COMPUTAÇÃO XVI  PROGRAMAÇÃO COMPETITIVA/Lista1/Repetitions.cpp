#include <iostream>
#include <string>

using namespace std;

int encontrarRepeticaoMaisLonga(const string& sequencia) {
    int maxRepeticao = 1;
    int repeticaoAtual = 1;

    for (size_t i = 1; i < sequencia.length(); ++i) {
        if (sequencia[i] == sequencia[i - 1]) {
            repeticaoAtual += 1;
            maxRepeticao = max(maxRepeticao, repeticaoAtual);
        } else {
            repeticaoAtual = 1;
        }
    }

    return maxRepeticao;
}

int main() {
    string sequenciaDNA;
    cin >> sequenciaDNA;

    cout << encontrarRepeticaoMaisLonga(sequenciaDNA) << endl;

    return 0;
}
