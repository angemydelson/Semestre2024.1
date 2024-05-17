#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int NC, N, h;
    cin >> NC; // Lê o número de cidades

    for (int i = 0; i < NC; i++) {
        cin >> N; 
        vector<int> alturas(N);

        for (int j = 0; j < N; j++) {
            cin >> alturas[j]; // Lê as alturas
        }

        sort(alturas.begin(), alturas.end()); 

        
        for (int j = 0; j < N; j++) {
            cout << alturas[j];
            if (j < N - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}


