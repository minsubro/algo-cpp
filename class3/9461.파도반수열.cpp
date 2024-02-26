#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long arr[102] = {0, 1, 1, 1, 2, 2};
    for(int i = 6; i < 101; i++) {
        arr[i] = arr[i - 1] + arr[i - 5];
    }
    int t; std::cin >> t;
    for(int i = 0; i < t; i++) {
        int x; std::cin >> x;
        std::cout << arr[x] << "\n";
    }
}