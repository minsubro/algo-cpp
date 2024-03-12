#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int inf = (~0U >> 2);

int main()
{
    int n, e; cin >> n >> e;
    vector<vector<pair<int, int> > > graph(n + 1);
    vector<vector<int> > dist(n + 1, vector<int>(n + 1, inf));
    for (int i = 0; i < e; i++) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        graph[v1].push_back({v2, cost});
        graph[v2].push_back({v1, cost});
    }
    vector<int> start(3, 1);
    cin >> start[1] >> start[2];
    for (int i = 0; i < 3; i++) {
        priority_queue<pair<int, int> > pq;
        dist[i][start[i]] = 0;
        pq.push({0, start[i]});
        while (!pq.empty()) {
            int now = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();
            if (cost > dist[i][now]) 
                continue;
            for (int j = 0; j < graph[now].size(); j++) {
                int next = graph[now][j].first;
                int n_cost = graph[now][j].second;
                if (cost + n_cost < dist[i][next]) {
                    dist[i][next] = cost + n_cost;
                    pq.push({-(cost + n_cost), next});
                    dist[i][next] = cost + n_cost;
                }
            }
        }
    }
    if ((dist[1][n] == inf && dist[2][n] == inf) || (dist[0][start[1]] == inf && dist[0][start[2]] == inf) || 
        (dist[0][1] == inf && dist[2][n] == inf) || (dist[0][2] == inf && dist[1][n] == inf))
        cout << -1;
    else {
        long long case1 = dist[0][start[1]] + dist[1][start[2]] + dist[2][n];
        long long case2 = dist[0][start[2]] + dist[2][start[1]] + dist[1][n];
        cout << (case1 < case2 ? case1 : case2);
    }
}