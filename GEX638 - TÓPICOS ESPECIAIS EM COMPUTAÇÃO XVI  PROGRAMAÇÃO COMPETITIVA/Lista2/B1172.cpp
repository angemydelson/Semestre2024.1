#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int somaQuadrados(int n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}


int maximaBasePiramide(int volumeTotal) {
    int n = 0;
    while (somaQuadrados(n + 1) <= volumeTotal) {
        n++;
    }
    return n;
}

int main() {
    int N, B;
    cin >> N >> B;
    vector<int> volumes(N);
    vector<int> precos(N);

    for (int i = 0; i < N; i++) {
        cin >> volumes[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> precos[i];
    }

 
    vector<pair<int, int>> itens;
    for (int i = 0; i < N; i++) {
        itens.push_back({volumes[i], precos[i]});
    }

    sort(itens.begin(), itens.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first * b.second > b.first * a.second; 
    });

    int volumeTotal = 0;
    for (const auto& item : itens) {
        if (B >= item.second) {
            volumeTotal += item.first;
            B -= item.second;
        }
    }

    int basePiramide = maximaBasePiramide(volumeTotal);
    cout << basePiramide << endl;

    return 0;
}
