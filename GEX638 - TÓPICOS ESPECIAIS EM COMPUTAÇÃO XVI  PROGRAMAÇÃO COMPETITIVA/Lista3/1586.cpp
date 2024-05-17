#include <iostream>
#include <vector>
#include <string>

int main() {
    using namespace std;
    int numNomes;
    vector<string> listaNomes(100005);
    vector<int> listaPontos(100005);

    cin >> numNomes;
    while (numNomes != 0) {
        long long somaPontosSemPesoB = 0;
        long long pesoTotalB = 0;
        for (int i = 1; i <= numNomes; i++) {
            listaPontos[i] = 0;
            cin >> listaNomes[i];
            for (char c : listaNomes[i])
                listaPontos[i] += c;

            somaPontosSemPesoB += listaPontos[i];
            pesoTotalB += listaPontos[i] * i;
        }

        int indiceEmpate = 0;
        long long pesoTotalA = 0;
        long long somaPontosSemPesoA = 0;
        for (int i = 1; i <= numNomes; i++) {
            pesoTotalB -= somaPontosSemPesoB;
            somaPontosSemPesoB -= listaPontos[i];

            somaPontosSemPesoA += listaPontos[i];
            pesoTotalA += somaPontosSemPesoA;
            if (pesoTotalA == pesoTotalB) {
                indiceEmpate = i;
                break;
            }
            if (pesoTotalA > pesoTotalB) break;
        }

        if (indiceEmpate == 0)
            cout << "Impossibilidade de empate.\n";
        else
            cout << listaNomes[indiceEmpate] << endl;

        cin >> numNomes;
    }
    return 0;
}
