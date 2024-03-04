#include <iostream>
#include <queue>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m; std::cin >> n >> m;
	int visit[101] = {0,};
	std::vector<int> v[101];
	std::queue<int> q;
	for (int i = 0; i < n + m; i++) {
		int x, y; std::cin >> x >> y;
			v[x].push_back(y);
	}
	q.push(1);
	visit[1] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == 100)
			break;
		for (int i = 1; i <= 6; i++) {
			int next = now + i;
			if (next > 100)
				continue;
			if (v[next].size() > 0)
				next = v[next][0];
			if (visit[next] == 0) {
				visit[next] = visit[now] + 1;
				q.push(next);
			}
		}
	}
	std::cout << visit[100] - 1;
}