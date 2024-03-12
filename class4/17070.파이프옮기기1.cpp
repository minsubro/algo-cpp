#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<vector<vector<int > > > dp(n + 1, vector<vector<int> >(n + 1, vector<int>(3, 0)));
    vector<vector<int> > map(n + 1, vector<int>(n + 1, 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    dp[1][2][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 3; j <= n; j++) {
            if (map[i][j] == 0) {
                dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
                dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
            }
            if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i - 1][j] == 0) {
                dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }
        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}