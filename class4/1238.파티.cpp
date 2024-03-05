#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

const int inf = (~0U >> 2);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, x; std::cin >> n >> m >> x;
    int *ret = new int [n + 1];
    std::fill(ret, ret + n, 0);
    std::vector<std::pair<int, int> > graph[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b, c; std::cin >> a >> b >> c;
        graph[a].push_back(std::make_pair(b, c));
    }
    int *dist = new int [n + 1];
    for (int i = 1; i <= n; i++) {
        std::priority_queue<std::pair<int, int> > pq;
        std::fill(dist, dist + n + 1, inf);
        dist[i] = 0;
        pq.push(std::make_pair(0, i));
        while (!pq.empty())
        {
            int cost = -pq.top().first;
            int now = pq.top().second;
            pq.pop();
            if (dist[now] < cost)
                continue ;
            for (int j = 0; j < graph[now].size(); j++) {
                int next = graph[now][j].first;
                int n_cost = graph[now][j].second;
                
                if (cost + n_cost < dist[next]) {
                    pq.push(std::make_pair(-(cost + n_cost), next));
                    dist[next] = cost + n_cost;
                }
            }
        }
        if (i == x) {
            for(int j = 1; j <= n; j++) {
                ret[j] += dist[j];
            }
        }
        else 
            ret[i] += dist[x];
    }
    int max = 0;
    for (int i = 1; i <= n; i++) {
        max = std::max(max, ret[i]);
    }
    std::cout << max;
}