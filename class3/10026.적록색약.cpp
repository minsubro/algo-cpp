#include <iostream>
#include <queue>

int dxdy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int Case1(char **map, int n)
{
    int cnt = 0;
    bool visit[101][101] = {0,};
    std::queue<std::pair<int, int> > q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) {
                cnt++;
                visit[i][j] = true;
                q.push(std::make_pair(i, j));
                while (!q.empty()) {
                    auto now = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int n_y = now.first + dxdy[k][0];
                        int n_x = now.second + dxdy[k][1];
                        if (n_y >= n || n_y < 0 || n_x >= n || n_x < 0)
                            continue ;
                        if (!visit[n_y][n_x] && map[n_y][n_x] == map[now.first][now.second]) {
                            visit[n_y][n_x] = true;
                            q.push(std::make_pair(n_y, n_x));
                        }
                    }
                }
            }
        }
    }
    return (cnt);
}

int Case2(char **map, int n)
{
    int cnt = 0;
    bool visit[101][101] = {0,};
    std::queue<std::pair<int, int> > q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) {
                cnt++;
                visit[i][j] = true;
                q.push(std::make_pair(i, j));
                while (!q.empty()) {
                    auto now = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int n_y = now.first + dxdy[k][0];
                        int n_x = now.second + dxdy[k][1];
                        if (n_y >= n || n_y < 0 || n_x >= n || n_x < 0)
                            continue ;
                        if (!visit[n_y][n_x]) {
                            if ((map[now.first][now.second] == 'R' || map[now.first][now.second] == 'G') && (map[n_y][n_x] == 'R' || map[n_y][n_x] == 'G')) {
                                visit[n_y][n_x] = true;
                                q.push(std::make_pair(n_y, n_x));
                            }
                            else if (map[n_y][n_x] == map[now.first][now.second]) {
                                visit[n_y][n_x] = true;
                                q.push(std::make_pair(n_y, n_x));
                            }
                        }
                    }
                }
                
            }
        }
    }
    return (cnt);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n; std::cin >> n;
    char **map = new char *[n];
    for (int i = 0; i < n; i++) {
        map[i] = new char [n];
        std::cin >> map[i];
    }
    std::cout << Case1(map, n) << " " << Case2(map, n) << std::endl;
}