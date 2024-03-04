#include <iostream>
#include <cmath>

int main()
{
	int n, m; std::cin >> n >> m;
	int map[510][510];
	for (int i = 0; i < 509; i++) {
		for (int j = 0; j < 509; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 4; i < n + 4; i++) {
		for (int j = 4; j < m + 4; j++) {
			std::cin >> map[i][j];
		}
	}
	int ret = 0;
	for (int i = 4; i < n + 4; i++) {
		for (int j = 4; j < m + 4; j++) {
			// I미노
			ret = std::max(ret, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3]);
			ret = std::max(ret, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j]);
			// O미노
			ret = std::max(ret, map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1]);
			// J/L미노
			ret = std::max(ret, map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 2][j + 1]);
			ret = std::max(ret, map[i][j] + map[i][j - 1] + map[i - 1][j - 1] + map[i - 2][j - 1]);
			ret = std::max(ret, map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1]);
			ret = std::max(ret, map[i][j] + map[i][j - 1] + map[i + 1][j - 1] + map[i + 2][j - 1]);

			ret = std::max(ret, map[i][j] + map[i - 1][j] + map[i - 1][j + 1] + map[i - 1][j + 2]);
			ret = std::max(ret, map[i][j] + map[i - 1][j] + map[i - 1][j - 1] + map[i - 1][j - 2]);
			ret = std::max(ret, map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2]);
			ret = std::max(ret, map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 1][j - 2]);

			// Z/S미노
			ret = std::max(ret, map[i][j] + map[i][j - 1] + map[i - 1][j - 1] + map[i - 1][j - 2]);
			ret = std::max(ret, map[i][j] + map[i][j - 1] + map[i + 1][j - 1] + map[i + 1][j - 2]);
			ret = std::max(ret, map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 1][j + 2]);
			ret = std::max(ret, map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2]);
			
			ret = std::max(ret, map[i][j] + map[i - 1][j] + map[i - 1][j - 1] + map[i - 2][j - 1]);
			ret = std::max(ret, map[i][j] + map[i - 1][j] + map[i - 1][j + 1] + map[i - 2][j + 1]);
			ret = std::max(ret, map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1]);
			ret = std::max(ret, map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1]);

			// T미노
			ret = std::max(ret, map[i][j] + map[i][j - 1] + map[i][j + 1] + map[i + 1][j]);
			ret = std::max(ret, map[i][j] + map[i][j - 1] + map[i][j + 1] + map[i - 1][j]);
			ret = std::max(ret, map[i][j] + map[i - 1][j] + map[i + 1][j] + map[i][j - 1]);
			ret = std::max(ret, map[i][j] + map[i - 1][j] + map[i + 1][j] + map[i][j + 1]);
		}
	}
	std::cout << ret;
}