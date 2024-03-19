#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = (~0U >> 2);

int main()
{
    int n, k; cin >> n >> k;
    int cnt = 0;
    vector<int> visit(100001, inf);
    priority_queue<pair<int, int> > pq;
    visit[n] = 0;
    pq.push({0, n});
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (now == k)
            ++cnt;
        if (visit[now] < cost) continue;
        if (now - 1 >= 0 && visit[now - 1] >= cost + 1) {
            pq.push({-(cost + 1), now - 1});
            visit[now - 1] = cost + 1;
        }
        if (now + 1 <= 100000 && visit[now + 1] >= cost + 1) {
            pq.push({-(cost + 1), now + 1});
            visit[now + 1] = cost + 1;
        }
        if (now * 2 <= 100000 && visit[now * 2] >= cost + 1) {
            pq.push({-(cost + 1), now * 2});
            visit[now * 2] = cost + 1;
        }
    }
    cout << visit[k] << "\n" << cnt;
}