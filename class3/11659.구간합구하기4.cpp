#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m; std::cin >> n >> m;
    int *arr = new int [n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x; std::cin >> x;
        arr[i] = arr[i - 1] + x;
    }
    for (int i = 0; i < m; i++) {
        int a, b; std::cin >> a >> b;
        std::cout << arr[b] - arr[a - 1] << "\n";
    }
}