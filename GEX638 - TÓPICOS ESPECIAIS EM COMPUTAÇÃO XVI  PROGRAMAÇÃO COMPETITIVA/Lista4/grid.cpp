#include <bits/stdc++.h>

using namespace std;

const int n = 7;
int grid[n][n];
int cont = 0;
string path;

bool is_free_pos(int i, int j) {
    if (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0) {
        return true;
    }
    return false;
}

void search(int s, int i, int j) {
    if (i == n - 1 && j == n - 1) {  // reached endpoint before visiting all
        if (s == path.size()) {
            cont++;
        }
        return;
    }

    if (s == path.size()) return;

    // Mark the current cell as visited
    grid[i][j] = 1;

    // Move in the direction specified by the current character in the path or try all possible moves if it's a '?'
    if (path[s] == '?' || path[s] == 'D') {
        if (is_free_pos(i + 1, j)) {
            search(s + 1, i + 1, j);
        }
    }
    if (path[s] == '?' || path[s] == 'U') {
        if (is_free_pos(i - 1, j)) {
            search(s + 1, i - 1, j);
        }
    }
    if (path[s] == '?' || path[s] == 'L') {
        if (is_free_pos(i, j - 1)) {
            search(s + 1, i, j - 1);
        }
    }
    if (path[s] == '?' || path[s] == 'R') {
        if (is_free_pos(i, j + 1)) {
            search(s + 1, i, j + 1);
        }
    }

    // Unmark the current cell
    grid[i][j] = 0;
}

int main() {
    cin >> path;

    // Initialize the grid
    memset(grid, 0, sizeof(grid));

    search(0, 0, 0);

    cout << cont << endl;
    return 0;
}
