#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }

    // Cria um vetor dp com tamanho x+1, inicializado com 0
    std::vector<int> dp(x + 1, 0);
    dp[0] = 1; // Há uma maneira de fazer a soma 0, que é não usando nenhuma moeda

    // Preenche o vetor dp
    for (int coin : coins) {
        for (int i = coin; i <= x; ++i) {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    // Imprime o número de maneiras de formar a soma x
    std::cout << dp[x] << std::endl;

    return 0;
}
