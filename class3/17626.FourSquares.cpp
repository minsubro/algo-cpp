#include <iostream>
#include <climits>
#include <cmath>

int main()
{
    int n; std::cin >> n;
    int arr[50001] = {0, 1, 2, 3};
    for (int i = 4; i <= n; i++) {
        int tmp = 1;
        while (true) {
            if (tmp * tmp > i)
                break ;
            tmp += 1;
        }
        int min = INT_MAX;
        for (int j = 1; j < tmp; j++) {
            min = std::min(min, arr[i - (j * j)] + 1);
        }
        arr[i] = min;
    }
    std::cout << arr[n];
}