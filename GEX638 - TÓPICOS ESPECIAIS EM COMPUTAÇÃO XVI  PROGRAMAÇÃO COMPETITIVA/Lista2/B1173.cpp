#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 10, entrada, somaEnt;
    vector<long long> x(n);
    cin >> entrada;
    somaEnt = entrada;
    for(int i = 0; i < n; i++) {
        x[0] = entrada;
        if (i > 0){
            somaEnt *= 2;
            x[i] = somaEnt;
        } 
    }
    
    for(int i = 0; i < n; i++) {
        cout << "N[" << i << "] = " << x[i] << endl;
    }
    
    return 0;
}
