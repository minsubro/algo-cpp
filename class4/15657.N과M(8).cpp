#include <iostream>
#include <algorithm>
#include <vector>
int n, m;

void recv(std::vector<int> &v, int s, int d, int *ret)
{
	for (int i = s; i < n; i++) {
		ret[d] = v[i];
		if (d == m - 1) {
			for (int j = 0; j < m; j++)
				std::cout << ret[j] << " ";
			std::cout << "\n";
		}
		else
			recv(v, i, d + 1, ret);
	}
}

int main()
{
	std::cin >> n >> m;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	int ret[8];
	recv(v, 0, 0, ret);
}