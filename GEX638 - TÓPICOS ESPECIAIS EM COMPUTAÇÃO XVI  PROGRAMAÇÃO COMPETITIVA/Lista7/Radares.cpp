#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para resolver um único caso de teste
int maxProfit(vector<int>& positions, vector<int>& profits, int K) {
    int N = positions.size();
    vector<int> dp(N, 0);
    vector<int> maxProfitUpTo(N, 0);
    
    dp[0] = profits[0];
    maxProfitUpTo[0] = dp[0];
    
    for (int i = 1; i < N; ++i) {
        // Encontrar o índice j mais distante tal que positions[i] - positions[j] >= K
        int left = 0, right = i - 1, best = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (positions[i] - positions[mid] >= K) {
                best = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Calcular dp[i] considerando o lucro do melhor j encontrado
        if (best != -1) {
            dp[i] = max(dp[i], maxProfitUpTo[best] + profits[i]);
        }
        
        // Também considerar o caso de não usar o radar i
        dp[i] = max(dp[i], profits[i]);
        
        // Atualizar o lucro máximo até a posição i
        if (i > 0) {
            maxProfitUpTo[i] = max(maxProfitUpTo[i-1], dp[i]);
        } else {
            maxProfitUpTo[i] = dp[i];
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> positions(N);
        vector<int> profits(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> positions[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> profits[i];
        }
        
        cout << maxProfit(positions, profits, K) << endl;
    }
    
    return 0;
}
