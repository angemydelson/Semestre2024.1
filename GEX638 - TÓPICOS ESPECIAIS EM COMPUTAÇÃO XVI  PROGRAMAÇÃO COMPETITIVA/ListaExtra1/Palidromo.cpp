#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Include this header for std::reverse

using namespace std;

int main() {
    string input;
    cin >> input;

    vector<int> freq(26, 0);
    for (char c : input) {
        freq[c - 'A']++;
    }

    int oddCount = 0;
    char oddChar = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 != 0) {
            oddCount++;
            oddChar = 'A' + i;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION";
        return 0;
    }

    string leftHalf = "";
    string middle = "";

    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            string part(freq[i] / 2, 'A' + i);
            leftHalf += part;
            if (freq[i] % 2 != 0) {
                middle = 'A' + i;
            }
        }
    }

    string rightHalf = leftHalf;
    reverse(rightHalf.begin(), rightHalf.end());

    cout << leftHalf + middle + rightHalf << endl;

    return 0;
}
