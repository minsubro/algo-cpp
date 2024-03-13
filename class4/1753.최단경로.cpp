#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int inf = (~0U >> 2);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e, s; cin >> v >> e >> s;
    vector<vector<pair<int, int> > > graph(v + 1);
    vector<int> dist(v + 1, inf);
    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < e; i++) {
        int v1, v2, distance; cin >> v1 >> v2 >> distance;
        graph[v1].push_back({v2, distance});
    }
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[now] < cost) continue;
        for (auto x: graph[now]) {
            int next = x.first;
            int n_cost = x.second;
            if (cost + n_cost < dist[next]) {
                pq.push({-(cost + n_cost), next});
                dist[next] = cost + n_cost;
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (dist[i] == inf)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

}