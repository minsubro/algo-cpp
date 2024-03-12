#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
    vector<pair<int, int> > arr;
    for (int i = 0; i < n; i++) {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int weight = arr[i - 1].first;
            int value = arr[i - 1].second;
            if (weight <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k];
}