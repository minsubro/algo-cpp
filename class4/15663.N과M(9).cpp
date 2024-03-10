#include <iostream>
#include <algorithm>
#include <vector>
int n, m;
int ret[8];
int g_check[10001];

void recv(std::vector<int> &v, int s, int d)
{
    int check[10001] = {0, };
    for (int i = 0; i < n; i ++) {
        if (check[v[i]] == 0 && g_check[v[i]] > 0) {
            ret[d] = v[i];
            check[v[i]] = 1;
            g_check[v[i]] -= 1;
        }
        else
            continue;
        if (d == m - 1) {
            for (int j = 0; j < m; j++) {
                std::cout << ret[j] << " ";
            }
            std::cout << "\n";
        }
        else
            recv(v, 0, d + 1);
        g_check[v[i]] += 1;
    }
}

int main()
{
    std::cin >> n >> m;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        g_check[v[i]] += 1;
    }
    std::sort(v.begin(), v.end());
    recv(v, 0, 0);
}