#include <iostream>
#include <queue>
#include <vector>

const int inf = (~0U>>2);

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<pair<long, long> > > graph(n + 1);
    priority_queue<pair<long, long> > pq;
    for (int i = 0; i < m; i++) {
        int s, e, c; cin >> s >> e >> c;
        graph[s].push_back({e, c});
    }
    int *dist = new int [n + 1];
    for (int i = 0; i < n + 1; i++)
        dist[i]= inf;
    int s, e; cin >> s >> e;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        long long now = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        if (dist[now] < cost) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            long long n_cost = graph[now][i].second;
            if (cost + n_cost < dist[next]) {
                dist[next] = cost + n_cost;
                pq.push({-dist[next], next});
            }
        }
    }
    std::cout << dist[e];
}