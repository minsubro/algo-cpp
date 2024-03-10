#include <iostream>
#include <queue>

int main()
{
    long long a, b;
    std::cin >> a >> b;
    std::priority_queue<std::pair<long long, int> > pq;
    pq.push({-a, 1});
    long long now = 0;
    long long cost = 0;
    while (!pq.empty()) {
        now = -pq.top().first;
        cost = pq.top().second;
        pq.pop();
        if (now >= b)
            break;
        pq.push({-(now * 2), cost + 1});
        pq.push({-((now * 10) + 1), cost + 1});
    }
    if (now == b)
        std::cout << cost;
    else
        std::cout << -1;
}