#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> Lis(vector<int> &arr, int n)
{
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    return (dp);
}

int main()
{
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> lis = Lis(arr, n);
    reverse(arr.begin(), arr.end());
    vector<int> r_lis = Lis(arr, n);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret = max(ret, lis[i] + r_lis[n - i - 1] - 1);
    }
    cout << ret;

}