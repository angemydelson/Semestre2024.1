#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::multiset<int> precosIngressos;
    int preco;

    // Lendo os preços dos ingressos e inserindo no multiset
    for (int i = 0; i < n; ++i) {
        std::cin >> preco;
        precosIngressos.insert(preco);
    }

    std::vector<int> precosMaximosClientes(m);
    // Lendo o preço máximo que cada cliente está disposto a pagar
    for (int i = 0; i < m; ++i) {
        std::cin >> precosMaximosClientes[i];
    }

    // Processando cada cliente
    for (int i = 0; i < m; ++i) {
        // Encontra o ingresso com o preço mais caro que não excede o máximo do cliente
        auto it = precosIngressos.upper_bound(precosMaximosClientes[i]);
        if (it == precosIngressos.begin()) {
            // Não há ingressos disponíveis que o cliente possa pagar
            std::cout << "-1\n";
        } else {
            // O iterador aponta para o primeiro elemento que é maior, então decrementamos
            --it;
            std::cout << *it << "\n";
            // Removendo o ingresso do conjunto, já que foi vendido
            precosIngressos.erase(it);
        }
    }

    return 0;
}
