#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int inf = (~0U >> 2);

int main()
{
    vector<int> dist(100001, inf);
    priority_queue<pair<int, int> > pq;
    int start, end; cin >> start >> end;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (cost > dist[now])
            continue;
        if (now + 1 <= 100000 && cost + 1 < dist[now + 1]) {
            pq.push({-(cost + 1), now + 1});
            dist[now + 1] = cost + 1;
        }
        if (now - 1 >= 0 && cost + 1 < dist[now - 1]) {
            pq.push({-(cost + 1), now - 1});
            dist[now - 1] = cost + 1;
        }
        if (now * 2 <= 100000 && dist[now * 2] > cost) {
            pq.push({-cost, now * 2});
            dist[now * 2] = cost;
        }
        
    }
    cout << dist[end];
}