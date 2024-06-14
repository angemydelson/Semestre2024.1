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

    std::vector<int> dp(x + 1, 0);
    dp[0] = 1; // Há uma maneira de fazer a soma 0, que é não usando nenhuma moeda

    for (int i = 1; i <= x; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = (dp[i] + dp[i - coin]) % MOD;
            }
        }
    }

    std::cout << dp[x] << std::endl;

    return 0;
}
