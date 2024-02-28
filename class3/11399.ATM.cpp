#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n; std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
    std::sort(vec.begin(), vec.end());
    int ret = vec[0];
    for (int i = 1; i < n; i++) {
        vec[i] += vec[i - 1];
        ret += vec[i];
    }
    std::cout << ret;
}