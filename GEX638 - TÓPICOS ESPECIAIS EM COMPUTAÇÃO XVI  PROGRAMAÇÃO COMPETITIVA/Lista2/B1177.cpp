#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 1000, T;
    vector<long long> x(n);
    cin >> T;
    int cont = 0;
    for(int i = 0; i < n; i++) {
        if ( cont == T){
            cont = 0;
        }
        x[i] = cont;
        cont += 1;

    }
    
    for(int i = 0; i < n; i++) {
        cout << "N[" << i << "] = " << x[i] << endl;
    }
    
    return 0;
}
