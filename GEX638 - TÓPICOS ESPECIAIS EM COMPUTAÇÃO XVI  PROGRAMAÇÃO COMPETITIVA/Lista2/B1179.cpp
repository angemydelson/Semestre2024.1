#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 5, valor, j = 0, k = 0;
    vector<long long> par(n);
    vector<long long> impar(n);

    for(int i = 0; i < 15; i++) {
        cin >> valor;
        if ( valor % 2 == 0){
            par[j] = valor;
            if (j == n-1){
                for(int l = 0; l < n; l++) {
                    cout << "par[" << l << "] = " << par[l] << endl;
                }
                j = 0;
                continue;
            }
            j += 1;
        } else {
            impar[k] = valor;
            if (k == n-1){
                for(int m = 0; m < n; m++) {
                    cout << "impar[" << m << "] = " << impar[m] << endl;
                }
                k = 0;
                continue;
            }
            k += 1;
        }
        if (i == 14 && k != n-1){
            for(int l = 0; l < k; l++) {
                cout << "impar[" << l << "] = " << impar[l] << endl;
            }
        }
        if (i == 14 && j != n-1){
            for(int l = 0; l < j; l++) {
                cout << "par[" << l << "] = " << par[l] << endl;
            }
        }
        

    }   
    return 0;
}
