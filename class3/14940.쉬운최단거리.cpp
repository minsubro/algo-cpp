#include <iostream>
#include <algorithm>
#include <queue>

int main()
{
	int n, m; std::cin >> n >> m;
	int dxdy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	std::queue<std::pair<int, int> > q;
	int **visit = new int *[n];
	int **map = new int *[n];
	for (int i = 0; i < n; i++) {
		visit[i] = new int [m];
		map[i] = new int [m];
	}
	std::fill(&visit[0][0], &visit[n - 1][m], 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 2) {
				q.push(std::make_pair(i, j));
				visit[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_y = y + dxdy[i][0];
			int n_x = x + dxdy[i][1];
			if (n_y < 0 || n_y >= n || n_x < 0 || n_x >= m)
				continue;
			if (map[n_y][n_x] == 1 && visit[n_y][n_x] == 0) {
				q.push(std::make_pair(n_y, n_x));
				visit[n_y][n_x] = visit[y][x] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0)
				std::cout << -1 << " ";
			else if (map[i][j] == 0)
				std::cout << 0 << " ";
			else
				std::cout << visit[i][j] - 1 << " ";
		}
		std::cout << "\n";
	}
}