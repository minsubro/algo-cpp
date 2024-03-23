#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int dxdy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int> > map(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    int ret = 0;
    while (true) {
        queue<pair<int, int> > q;
        vector<vector<bool> > visit(n, vector<bool> (m, true));
        vector<vector<int> > copy = map;
        visit[0][0] = false;
        q.push({0, 0});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int n_x = x + dxdy[i][0];
                int n_y = y + dxdy[i][1];
                if (n_x < 0 || n_x >= m || n_y < 0 || n_y >= n)
                    continue;
                if (copy[n_y][n_x] == 0 && visit[n_y][n_x]) {
                    visit[n_y][n_x] = false;
                    q.push({n_x, n_y});
                }
                if (copy[n_y][n_x] != 0) {
                    copy[n_y][n_x]++;
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (copy[i][j] > 2) {
                    map[i][j] = 0;
                    flag = true;
                }
            }
        }

        if (flag == false)
            break;
        ret++;
    }
    cout << ret;
}