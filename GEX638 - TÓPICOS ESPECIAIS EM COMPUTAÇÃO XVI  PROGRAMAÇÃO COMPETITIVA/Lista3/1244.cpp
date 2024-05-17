#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;

    int N;
    stringstream fluxo;
    string frase, palavra;
    vector<string> palavras;

    cin >> N;
    cin.ignore();

    auto comp = [](const string &a, const string &b) { return a.length() > b.length(); };

    for (int i = 0; i < N; ++i) {
        getline(cin, frase);

        fluxo.clear();
        fluxo.str(frase);
        palavras.clear();
        while (fluxo >> palavra) {
            palavras.push_back(palavra);
        }

        int n = palavras.size();
        for (int i = 0; i < n; ++i) {
            int j = i;
            int k = j - 1;
            while (k > -1 && comp(palavras[j], palavras[k])) {
                swap(palavras[k], palavras[j]);
                --j;
                --k;
            }
        }

        cout << palavras[0];
        for (int i = 1; i < palavras.size(); ++i) {
            cout << ' ' << palavras[i];
        }
        cout << endl;
    }

    return 0;
}
