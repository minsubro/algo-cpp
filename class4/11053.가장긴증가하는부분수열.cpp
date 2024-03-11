#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n; std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    int dp[1001] = {0,};
    std::fill(dp, dp + 1001, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] < v[j]) {
                dp[j] = std::max(dp[i] + 1, dp[j]);
            }
        }
    }
    int ret = 0;
    for (int i = 1; i < n + 1; i++) {
        ret = std::max(ret, dp[i]);
    }
    for (int i = 1; i < n + 1; i++) {
        std::cout << dp[i] << " ";
    }
    std::cout << ret;
}