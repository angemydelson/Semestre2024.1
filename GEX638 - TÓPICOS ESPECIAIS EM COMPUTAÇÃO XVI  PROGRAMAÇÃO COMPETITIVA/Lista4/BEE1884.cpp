#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

int main() {
    while (true) {
        int N, D;
        std::cin >> N >> D;
        
        // Se receber 0 0, termina o loop
        if (N == 0 && D == 0) break;

        std::string numero;
        std::cin >> numero;

        std::stack<char> pilha;
        int digitosParaRemover = D;

        // Processar cada dígito
        for (char digito : numero) {
            // Enquanto houver dígitos a remover e a pilha não estiver vazia,
            // e o topo da pilha for menor que o dígito atual
            while (!pilha.empty() && digitosParaRemover > 0 && pilha.top() < digito) {
                pilha.pop();
                digitosParaRemover--;
            }
            
            // Se ainda há espaço para mais dígitos na resposta final
            if (pilha.size() < (N - D)) {
                pilha.push(digito);
            }
        }

        // Construir o número máximo
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
