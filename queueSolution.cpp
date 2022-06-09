#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>
#include <ctime>
#include <stdio.h>
#include <queue>
#include <utility>

const int MAXN = 1e4 + 10;
int n, m;
std::vector<std::bitset<MAXN>> p;

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
    int x, y;
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (p[i][j]) {
                answer++;
                q.push({i, j});
                while (!q.empty()) {
                    auto current = q.front();
                    q.pop();
                    x = current.first;
                    y = current.second;
                    p[x][y] = false;
                    if (x > 0 && p[x - 1][y]) {
                        q.push({x - 1, y});
                        p[x - 1][y] = false;
                    }
                    if (x < n - 1 && p[x + 1][y]) {
                        q.push({x + 1, y});
                        p[x + 1][y] = false;
                    }
                    if (y > 0 && p[x][y - 1]) {
                        q.push({x, y - 1});
                        p[x][y - 1] = false;
                    }
                    if (y < m - 1 && p[x][y + 1]) {
                        q.push({x, y + 1});
                        p[x][y + 1] = false;
                    }
                }
            }
        }
    }
    std::cout << answer << '\n';

#ifdef _DEBUG
	std::cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}