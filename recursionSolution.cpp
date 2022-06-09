#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>
#include <ctime>
#include <stdio.h>

const int MAXN = 1e4 + 10;
int n, m;
std::vector<std::bitset<MAXN>> p;

void solve(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return;
    }
    p[x][y] = false;
    if (x > 0 && p[x - 1][y]) {
        p[x - 1][y] = false;
        solve(x - 1, y);
    }
    if (x < n - 1 && p[x + 1][y]) {
        p[x + 1][y] = false;
        solve(x + 1, y);
    }
    if (y > 0 && p[x][y - 1]) {
        p[x][y - 1] = false;
        solve(x, y - 1);
    }
    if (y < m - 1 && p[x][y + 1]) {
        p[x][y + 1] = false;
        solve(x, y + 1);
    }
}

// main.exe <inputfile>
int main(int argc, char *argv[]) {
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
    }
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(false);
    
    std::cin >> n >> m;
    p.resize(n);
    bool input;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> input;
            p[i][j] = input;
        }
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (p[i][j]) {
                solve(i, j);
                answer++;
            }
        }
    }
    std::cout << answer << '\n';

#ifdef _DEBUG
	std::cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}