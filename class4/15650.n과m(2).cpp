#include <iostream>
int n, m;

void recv(int s, int d, int *ret)
{
	for (int i = s; i <= n; i++) {
		ret[d] = i;
		if (d == 0) {
			for(int j = m - 1; j >= 0; j--) {
				std::cout << ret[j] << " ";
			}
			std::cout << "\n";
		}
		else
			recv(i + 1, d - 1, ret);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
	int ret[8];
	recv(1, m - 1, ret);
}