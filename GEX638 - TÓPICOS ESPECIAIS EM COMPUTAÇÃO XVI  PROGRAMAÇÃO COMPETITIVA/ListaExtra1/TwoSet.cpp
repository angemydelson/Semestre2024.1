#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    long long sum = (long long)n * (n + 1) / 2;

    if (sum % 2 != 0) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        std::vector<int> set1, set2;
        long long target = sum / 2;
        for (int i = n; i > 0; --i) {
            if (target >= i) {
                set1.push_back(i);
                target -= i;
            } else {
                set2.push_back(i);
            }
        }
        
        std::cout << set1.size() << "\n";
        for (int num : set1) {
            std::cout << num << " ";
        }
        std::cout << "\n";

        std::cout << set2.size() << "\n";
        for (int num : set2) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
