#include <iostream>
#include <vector>
#include <queue>

int **initVisit(int n) {
	int **visit = new int *[n + 1];
	for (int i = 0; i < n; i++) {
			visit[i] = new int [n];
			for (int j = 0; j < n; j++) {
				visit[i][j] = 0;
			}
		}
	return (visit);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int ret = 0;
	int n, m; std::cin >> n >> m;
	int **visit = initVisit(n + 1);
	std::vector<int> graph[n + 1];
	for (int i = 0; i < m; i++) {
		int a, b; std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i < n + 1; i++) {
		if (graph[i].size() == 0)
			ret += 1;
		else {
			std::queue<int> q;
			int cnt = 0;
			for (size_t j = 0; j < graph[i].size(); j++) {
				int node = graph[i][j];
				if (visit[i][node] == 0) {
					cnt += 1;
					visit[i][node] = 1;
					visit[node][i] = 1;
					q.push(node);
				}
			}
			while (!q.empty()) {
				int next = q.front();
				q.pop();
				for (size_t k = 0; k < graph[next].size(); k++) {
					int n_node = graph[next][k];
					if (visit[next][n_node] == 0) {
						visit[next][n_node] = 1;
						visit[n_node][next] = 1;
						q.push(n_node);
					}
				}
			}
			if (cnt > 0)
				ret += 1;
		}
	}
	std::cout << ret;
}