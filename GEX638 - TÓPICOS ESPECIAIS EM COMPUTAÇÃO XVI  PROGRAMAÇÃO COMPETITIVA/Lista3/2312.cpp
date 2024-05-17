/*Alguém deixou o quadro de medalhas das olimpíadas fora de ordem. 
Seu programa deve colocá-lo na ordem correta. 
A ordem dos países no quadro de medalhas é dada pelo número de medalhas de ouro. 
Se há empate em medalhas de ouro, a nação que tiver mais medalhas de prata fica a frente. 
Havendo empate em medalhas de ouro e prata, fica mais bem colocado o país com mais medalhas de bronze. 
Se dois ou mais países empatarem nos três tipos de medalhas, seu programa deve mostrá-los em ordem alfabética.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Pais {
    string nome;
    int ouro;
    int prata;
    int bronze;
};

int main() {
    int N;
    cin >> N;

    vector<Pais> paises(N);

    
    for (int i = 0; i < N; i++) {
        cin >> paises[i].nome >> paises[i].ouro >> paises[i].prata >> paises[i].bronze;
    }

    
    sort(paises.begin(), paises.end(), [](const Pais &a, const Pais &b) {
        if (a.ouro != b.ouro) return a.ouro > b.ouro;
        if (a.prata != b.prata) return a.prata > b.prata;
        if (a.bronze != b.bronze) return a.bronze > b.bronze;
        return a.nome < b.nome; // Critério de desempate alfabético
    });

    // Mostrando a lista ordenada de países
    for (const auto &pais : paises) {
        cout << pais.nome << " " << pais.ouro << " " << pais.prata << " " << pais.bronze << endl;
    }

    return 0;
}
