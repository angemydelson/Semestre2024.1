/*
Clientes de restaurantes
Você recebe os horários de chegada e saída denclientes em um restaurante.
Qual foi o número máximo de clientes no restaurante em qualquer horário?
Entrada
A primeira linha de entrada tem um número inteiron: o número de clientes.
Depois disso, existemnlinhas que descrevem os clientes. Cada linha tem dois 
inteirosaeb: os horários de chegada e saída de um cliente.
Você pode presumir que todos os horários de chegada e saída são distintos.
Saída
Imprima um número inteiro: o número máximo de clientes.
Restrições

1 \le n \le 2 \cdot 10^5
1 \le a < b \le 10^9

Exemplo
Entrada:
3
5 8
2 4
3 9

Saída:
2
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> eventos; // Usaremos um par onde o primeiro elemento é o tempo e o segundo o tipo de evento (+1 para chegada, -1 para saída)

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        eventos.push_back({a, 1});  // Evento de chegada
        eventos.push_back({b, -1}); // Evento de saída
    }

    // Ordenando os eventos
    sort(eventos.begin(), eventos.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        if (x.first == y.first) return x.second > y.second; // Prioriza saídas em caso de empate
        return x.first < y.first;
    });

    int clientesAtuais = 0, maxClientes = 0;
    
    // Varrendo os eventos
    for (auto& evento : eventos) {
        clientesAtuais += evento.second;
        maxClientes = max(maxClientes, clientesAtuais);
    }

    cout << maxClientes << endl;

    return 0;
}
