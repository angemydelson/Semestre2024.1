/*Você tem que processarntarefas. Cada tarefa tem uma duração e um prazo, e você processará as tarefas 
em alguma ordem, uma após a outra. Sua recompensa por uma tarefa édfondedé o seu prazo efé o seu tempo 
de término. (O horário de início é0, e você terá que processar todas as tarefas, mesmo que uma tarefa 
gere uma recompensa negativa.)
Qual é a sua recompensa máxima se você agir de maneira otimizada?
Entrada
A primeira linha de entrada tem um número inteiron: o número de tarefas.
Depois disso, existemnlinhas que descrevem as tarefas. Cada linha tem dois inteirosaed: a duração e o prazo da tarefa.
Saída
Imprima um número inteiro: a recompensa máxima.
Restrições

1 \le n \le 2 \cdot 10^5
1\le a,d \le 10^6

Exemplo
Entrada:
3 
6 10 
8 15 
5 12

Saída:
2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> tarefas(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> tarefas[i].first >> tarefas[i].second;  
    }

    // Ordenando as tarefas por duração (menor duração primeiro)
    std::sort(tarefas.begin(), tarefas.end());

    long long tempoAtual = 0;
    long long recompensaTotal = 0;

    // Processando as tarefas
    for (const auto& tarefa : tarefas) {
        int duracao = tarefa.first;
        int prazo = tarefa.second;

        tempoAtual += duracao; // Atualizando o tempo de término após a tarefa
        recompensaTotal += (prazo - tempoAtual); // Calculando a recompensa para esta tarefa
    }

    std::cout << recompensaTotal << std::endl;
    return 0;
}
