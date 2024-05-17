#include <iostream>
#include <cmath>
using namespace std;


long long totalCartas(int N) {
    return (3LL * N * N + N) / 2;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        long long C;
        cin >> C;
        
        
        long long esq = 1, dir = (long long) sqrt(2 * C / 3), meio, res = 0;
        while (esq <= dir) {
            meio = esq + (dir - esq) / 2;
            if (totalCartas(meio) <= C) {
                res = meio;  
                esq = meio + 1;  
            } else {
                dir = meio - 1;  
            }
        }
        
        cout << res << endl;
    }
    
    return 0;
}

