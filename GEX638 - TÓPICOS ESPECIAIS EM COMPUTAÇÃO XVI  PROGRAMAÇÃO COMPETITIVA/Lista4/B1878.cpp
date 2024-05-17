#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<int> c(N);
        for (int i = 0; i < N; i++) {
            cin >> c[i];
        }

        // Criando um conjunto para armazenar as somas dos scores
        set<int> scores;
        bool unique = true;

        // Gerar todas as possíveis combinações de classificações
        for (int t1 = 1; t1 <= M && unique; ++t1) {
            for (int t2 = 1; (t2 <= M || N < 2) && unique; ++t2) {
                for (int t3 = 1; (t3 <= M || N < 3) && unique; ++t3) {
                    int score = 0;
                    if (N >= 1) score += c[0] * t1;
                    if (N >= 2) score += c[1] * t2;
                    if (N >= 3) score += c[2] * t3;

                    // Verificando se a pontuação já existe no conjunto
                    if (scores.find(score) != scores.end()) {
                        unique = false;
                    } else {
                        scores.insert(score);
                    }
                }
            }
        }

        if (unique) {
            cout << "Lucky Denis!" << endl;
        } else {
            cout << "Try again later, Denis..." << endl;
        }
    }
    return 0;
}
