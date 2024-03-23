#include <iostream>
#include <vector>

using namespace std;

const int dxdy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
# define RIGHT 0
# define DOWN  1
# define LEFT 2
# define UP 3


void spread(vector<vector<int> > &map, int r, int c) 
{
    vector<vector<int> > tmp(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] != -1) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int dy = i + dxdy[k][0];
                    int dx = j + dxdy[k][1];
                    if (dy < 0 || dy >= r || dx < 0 || dx >= c || map[dy][dx] == -1)
                        continue;
                    cnt++;
                    tmp[dy][dx] += map[i][j] / 5;
                }
                map[i][j] -= (map[i][j] / 5) * cnt;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            map[i][j] += tmp[i][j];
        }
    }
}

void    Exec(vector<vector<int> > &map, int r, int c, pair<int, int> pos, int *direction)
{
    int y = pos.first;
    int x = pos.second + 1;
    int tmp1 = 0;
    int tmp2 = 0;
    int i = 0;
    while (true) {
        if (map[y][x] == -1)
            break ;
        tmp2 = map[y][x];
        map[y][x] = tmp1;
        y += dxdy[direction[i]][0];
        x += dxdy[direction[i]][1];
        if (direction[i] == RIGHT && (x == c - 1))
            i++;
        else if (direction[i] == UP && (y == 0 || y == pos.first))
            i++;
        else if (direction[i] == LEFT && x == 0)
            i++;
        else if (direction[i] == DOWN && (y == r - 1 || y == pos.first))
            i++;
        tmp1 = tmp2;
    }
}


void purification(vector<vector<int> > &map, int r, int c, vector<pair<int, int> > air)
{
    int upper[4] = {RIGHT, UP, LEFT, DOWN};
    int lower[4] = {RIGHT, DOWN, LEFT, UP};
    Exec(map, r, c, air[0], upper);
    Exec(map, r, c, air[1], lower);
}

int main()
{
    int r, c, t; cin >> r >> c >> t;
    vector<vector<int> > map(r, vector<int>(c));
    vector<pair<int, int> > air;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1)
                air.push_back({i, j});
        }
    }
    while (t--) {
        spread(map, r, c);
        purification(map, r, c, air);
    }
    int ret = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] > 0)
                ret += map[i][j];
        }
    }
    cout << ret;
}