#include <iostream>
#include <climits> 
#include <vector>
#include <set>

int distance(std::string &a, std::string &b) {
    int ret = 4;
    for (int i = 0; i < 4; i++) {
        if (a[i] == b[i])
            ret -= 1;
    }
    return (ret);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t, n; std::cin >> t;
    for (t; t > 0; t--) {
        std::cin >> n;
        std::set<std::string> set;
        std::vector<std::string> strs(n);
        for (int i = 0; i < n; i++) {
            std::cin >> strs[i];
        }
        if (n > 32) {
            std::cout << "0\n";
            continue ;
        }
        int min = INT_MAX;
        size_t size = strs.size();
        for (size_t i = 0; i < size; i++) {
            for (size_t j = i + 1; j < size; j++) {
                for (size_t k = j + 1; k < size; k++) {
                    min = std::min(min, distance(strs[i], strs[j]) + distance(strs[i], strs[k]) + distance(strs[j], strs[k]));
                }
            }
        }
        std::cout << min << "\n";
    }
}