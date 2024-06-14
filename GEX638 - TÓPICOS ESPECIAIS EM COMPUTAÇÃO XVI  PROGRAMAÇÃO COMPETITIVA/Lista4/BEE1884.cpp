#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

int main() {
    while (true) {
        int N, D;
        std::cin >> N >> D;
        
       
        if (N == 0 && D == 0) break;

        std::string numero;
        std::cin >> numero;

        std::stack<char> pilha;
        int digitosParaRemover = D;

       
        for (char digito : numero) {
          
            while (!pilha.empty() && digitosParaRemover > 0 && pilha.top() < digito) {
                pilha.pop();
                digitosParaRemover--;
            }
            
         
            if (pilha.size() < (N - D)) {
                pilha.push(digito);
            }
        }

       
        std::string resultado;
        while (!pilha.empty()) {
            resultado.push_back(pilha.top());
            pilha.pop();
        }
        std::reverse(resultado.begin(), resultado.end());


        std::cout << resultado << std::endl;
    }
    
    return 0;
}
