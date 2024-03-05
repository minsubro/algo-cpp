#include <iostream>
#include <vector>

int main()
{
    int n; std::cin >> n;
    std::vector<int> v[n];
    for (int i = 0; i < n; i++) {
        v[i] = std::vector<int>(3);
        std::cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    for (int i = 1; i < n; i++) {
        v[i][0] += std::min(v[i - 1][1], v[i - 1][2]);
        v[i][1] += std::min(v[i - 1][0], v[i - 1][2]);
        v[i][2] += std::min(v[i - 1][0], v[i - 1][1]);
    }
    std::cout << std::min(std::min(v[n - 1][0], v[n - 1][1]), v[n - 1][2]);
}