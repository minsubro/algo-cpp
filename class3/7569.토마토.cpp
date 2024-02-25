#include <iostream>
#include <queue>

using namespace std;
int m, n, h;

bool CheckMap(int ***map) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (map[i][j][k] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int MaxElement(int ***map) {
    int ret = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (map[i][j][k] > ret) {
                    ret = map[i][j][k];
                }
            }
        }
    }
    return (ret);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> m >> n >> h;
    int ***map = new int** [h];
    queue<pair<int, pair<int, int> > > q;
    for (int i = 0; i < h; i++) {
        map[i] = new int *[n];
        for (int j = 0; j < n; j++) {
            map[i][j] = new int[m];
            for (int k = 0; k < m; k++) {
                int x = 0;
                cin >> x;
                if (x == 1)
                    q.push(make_pair(i, make_pair(j, k)));
                map[i][j][k] = x;
            }
        }
    }

    int dxdydz[6][3] = {
        {1, 0, 0}, {-1, 0, 0},
        {0, 1, 0}, {0, -1, 0},
        {0, 0, 1}, {0, 0, -1}
    };

    while (q.size()) {
        pair<int, pair<int, int> > xyz = q.front();
        q.pop();
        for (int *tmp : dxdydz) {
            int n_z = xyz.first + tmp[0];
            int n_y = xyz.second.first + tmp[1];
            int n_x = xyz.second.second + tmp[2];
            if (n_z < 0 || n_z >= h || n_y >= n || n_y < 0 || n_x >= m || n_x < 0)
                continue;
            if (map[n_z][n_y][n_x] == 0) {
                map[n_z][n_y][n_x] = map[xyz.first][xyz.second.first][xyz.second.second] + 1;
                q.push(make_pair(n_z, make_pair(n_y, n_x)));
            }
        }
    }
    if (!CheckMap(map))
        cout << -1;
    else
        cout << MaxElement(map) - 1;
}
