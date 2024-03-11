#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; std::cin >> n >> m;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int [n + 1];
        fill(arr[i], arr[i] + n + 1, 0);
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] += arr[i][j - 1];
        }
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int ret = 0;
        while (true) {
            if (y1 < y2) {
                ret += arr[x1 - 1][y2] - arr[x1 - 1][y1 - 1]; 
            }
            else
                ret += arr[x1 - 1][y1] - arr[x1 - 1][y2 - 1];
            if (x1 == x2)
                break ;
            if (x1 > x2) 
                x1--;
            else
                x1++;
        }
        std::cout << ret << "\n";
    }
}