#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstring>

const char* outputFile;
bool allWhite = false;
int n, m;

// testGenerator <n> <m> <outputfile> <white (for all white tests)>
int main(int argc, char *argv[]) {
    if (argc < 3) {
        outputFile = "test.in";
        n = 100;
        m = 100;
    }
    else {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
        outputFile = argv[3];
    }
    if (strcmp(argv[argc - 1], "white") == 0) {
        allWhite = true;
    }
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(false);
    freopen(outputFile, "w", stdout);
    srand(time(0));

    std::cout << n << " " << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << (allWhite ? 1 : (rand() % 2)) << " ";
        }
        std::cout << '\n';
    }

#ifdef _DEBUG
	std::cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}