#include <iostream>
#include <vector>

using namespace std;

const int inf = (~0U >> 2);

typedef struct {
    int v1;
    int v2;
    int cost;
} Edge;

bool Bellman(vector<Edge> &edge, int s, int n)
{
    vector<int> dist(n + 1, inf);
    dist[s] = 0;
    
    for (int i = 1; i < n; i++) {
        for (size_t j = 0; j < edge.size(); j++) {
            int v1 = edge[j].v1;
            int v2 = edge[j].v2;
            int cost = edge[j].cost;
            dist[v2] = min(dist[v2], dist[v1] + cost);
        }
    }
    for (size_t j = 0; j < edge.size(); j++) {
            int v1 = edge[j].v1;
            int v2 = edge[j].v2;
            int cost = edge[j].cost;
            if (dist[v2] > dist[v1] + cost)
                return (true);
    }
    return (false);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--)
    {
        int n, m, w; cin >> n >> m >> w;
        vector<Edge> edge;
        int v1, v2, cost;
        for (int i = 0; i < m; i++) {
            cin >> v1 >> v2 >> cost;
            edge.push_back({v1, v2, cost});
            edge.push_back({v2, v1, cost});
        }
        for (int i = 0; i < w; i++) {
            cin >> v1 >> v2 >> cost;
            edge.push_back({v1, v2, -cost});
        }
        
        
        cout << (Bellman(edge, 0, n) ? "YES" : "NO") << "\n";
    }
}