#include <iostream>
#include <vector>

int main() {
    // Calcular fatoriais até que eles ultrapassem 100000
    std::vector<int> factorials;
    int fact = 1;
    int i = 1;
    
    while (fact <= 100000) {
        factorials.push_back(fact);
        i++;
        if (fact > 100000 / i)  // Prevenir overflow e fatoriais desnecessários
            break;
        fact *= i;
    }

    int N;
    std::cin >> N;
    
    int count = 0;
    for (int j = factorials.size() - 1; j >= 0; j--) {
        while (N >= factorials[j]) {
            N -= factorials[j];
            count++;
        }
    }

    std::cout << count << std::endl;
    
    return 0;
}
