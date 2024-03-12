#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b; cin >> a >> b;
    vector<vector<int> > dp(b.size() + 1, vector<int>(a.size() + 1, 0));
    for (int i = 1; i < b.size() + 1; i++) {
        for (int j = 1; j < a.size() + 1; j++) {
            if (a[j - 1] == b[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    std::cout << dp[b.size()][a.size()];
}