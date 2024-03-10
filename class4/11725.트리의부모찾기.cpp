#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int n; std::cin >> n;
    std::vector<std::vector<int> > v(n + 1);
    int visit[100001] = {0, };
    for (int i = 1; i < n; i++) {
        int x, y; std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    std::queue<int> q({1});
    visit[1] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < v[node].size(); i++) {
            int child = v[node][i];
            if (visit[child] == 0) {
                visit[child] = node;
                q.push(child);
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        std::cout << visit[i] << "\n";
    }
}