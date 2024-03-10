#include <iostream>
#include <set>
int n, m;
int ret[8];

void recv(std::set<int> &set, std::set<int>::iterator s, int d)
{
    for (auto it = s; it != set.end(); it++)
    {
        ret[d] = *it;
        if (d == m - 1) {
            for (int j = 0; j < m; j++) {
                std::cout << ret[j] << " ";
            }
            std::cout << "\n";
        }
        else
            recv(set, it, d + 1);
    }
}

int main()
{
    std::cin >> n >> m;
    std::set<int> set;
    for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
        set.insert(x);
    }
    recv(set, set.begin(), 0);
}