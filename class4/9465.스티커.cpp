#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--)
    {
        int n; cin >> n;
        vector<vector<int>> arr(2);
        int *dp[2];
        for (int i = 0; i < 2; i++) {
            arr[i] = vector<int> (n);
            dp[i] = new int [n];
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                dp[i][j] = arr[i][j];                
            }
        }
        if (n == 1) {
            std::cout << max(arr[0][0], arr[1][0]) << std::endl;
            continue;
        }
        dp[0][1] = arr[0][1] + arr[1][0];
        dp[1][1] = arr[1][1] + arr[0][0];
        for (int i = 2; i < n; i++) {
            dp[0][i] = arr[0][i] + max(dp[1][i - 1], max(dp[1][i - 2], dp[0][i - 2]));
            dp[1][i] = arr[1][i] + max(dp[0][i - 1], max(dp[0][i - 2], dp[1][i - 2]));
        }
        std::cout << max(dp[1][n - 1], dp[0][n - 1]) << "\n";
    }
    
}