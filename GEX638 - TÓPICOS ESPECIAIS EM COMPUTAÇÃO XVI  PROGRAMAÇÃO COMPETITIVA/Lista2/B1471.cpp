#include <iostream>
#include <set>

using namespace std;

int main() {
    int totalMergulhadores, retornaram, identificador;

    while (cin >> totalMergulhadores >> retornaram) {  // Lê até o EOF
        set<int> retornados;  // Set para armazenar os identificadores dos que retornaram

        for (int i = 0; i < retornaram; i++) {
            cin >> identificador;
            retornados.insert(identificador);  // Adiciona ao set
        }

        bool todosRetornaram = true;
        for (int i = 1; i <= totalMergulhadores; i++) {
            if (retornados.find(i) == retornados.end()) {  // Se i não está no set
                cout << i << " ";
                todosRetornaram = false;
            }
        }

        if (todosRetornaram) {
            cout << "*";
        }
        cout << endl;  // Nova linha após cada caso de teste
    }

    return 0;
}