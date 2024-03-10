#include <iostream>
#include <vector>

int main()
{
    int n; std::cin >> n;
    std::vector<std::vector<int> > v(n);
    int dp[500][500] = {0, };
    for (int i = 0; i < n; i++) {
        v[i] = std::vector<int> (i + 1);
        for (int j = 0; j < i + 1; j++) {
            std::cin >> v[i][j];
        }
    }
    dp[0][0] = v[0][0];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < i + 1; j++) {
            dp[i + 1][j] = std::max(dp[i + 1][j], v[i + 1][j] + dp[i][j]);
            dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], v[i + 1][j + 1] + dp[i][j]);
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret = std::max(dp[n - 1][i], ret);
    }
    std::cout << ret;
}