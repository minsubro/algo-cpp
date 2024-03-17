#include <iostream>
#include <vector>

using namespace std;

int ret;
int n, m;
int dxdy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void sol(vector<string> &map, int x, int y, vector<bool> &check, int cnt) 
{
	check[map[y][x] - 65] = false;
	for (int i = 0 ; i < 4; i++) {
		int n_x = x + dxdy[i][0];
		int n_y = y + dxdy[i][1];
		if (n_x >= m || n_x < 0 || n_y >= n || n_y < 0)
			continue;
		if (check[map[n_y][n_x] - 65]) {
			sol(map, n_x, n_y, check, cnt + 1);
		}
	}
	check[map[y][x] - 65] = true;
	if (cnt > ret)
		ret = cnt;
}

int main()
{
	cin >> n >> m;
	vector<string> map(n);
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	vector<bool> check(26, true);
	sol(map, 0, 0, check, 1);
	cout << ret;
}