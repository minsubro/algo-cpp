#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int ret = 0;

void dfs(vector<vector<int> > map)
{
    queue<pair<int, int> > q;
    static const int dxdy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 2) {
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int low = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int n_low = low + dxdy[i][0];
            int n_col = col + dxdy[i][1];
            if (n_low < 0 || n_low >= n || n_col < 0 || n_col >= m)
                continue;
            if (map[n_low][n_col] == 0) {
                map[n_low][n_col] = 2;
                q.push({n_low, n_col});
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0)
                cnt++;
        }
    }
    ret = max(ret, cnt);
}

void sol(vector<vector<int> >& map, int low, int col, int d) {
    bool first = true;
    for (int i = low; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (first) {
                j = col;
                first = false;
            }
            if (map[i][j] == 0) {
                map[i][j] = 1;
                if (d == 2) {
                    dfs(map);
                }
                else
                    sol(map, i, j, d + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<int> > map(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    sol(map, 0, 0, 0);
    cout << ret;
}