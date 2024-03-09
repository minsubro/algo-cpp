#include <iostream>
#include <algorithm>
#include <vector>
int n, m;
int check[10001];

void	recv(std::vector<int> &arr, int s, int d, int *ret)
{
	for (int i = 0; i < n; i++) {
		if (check[arr[i]] == 0) {
			ret[d] = arr[i];
			check[arr[i]] = 1;
		}
		else
			continue;
		if (d == 0) {
			for (int j = m - 1; j >= 0; j--) {
				std::cout << ret[j] << " ";
			}
			std::cout << "\n";
		}
		else
			recv(arr, i + 1, d - 1, ret);
		check[arr[i]] = 0;
	}
}

int main()
{
	std::cin >> n >> m;
	std::vector<int> arr(n);
	int ret[8];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	std::sort(arr.begin(), arr.end());
	recv(arr, 0, m - 1, ret);
}