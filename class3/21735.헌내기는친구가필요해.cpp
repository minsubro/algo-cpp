#include <iostream>
#include <vector>
#include <queue>

int n, m;
int dxdy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    std::vector<std::string> vec;
    std::queue<std::pair<int, int> > q;
    int ret = 0;
    std::cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        vec.push_back(str);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (vec[i][j] == 'I') {
                q.push(std::make_pair(i, j));
            }
        }
    }
    while (!q.empty()) {
        auto xy = q.front();
        q.pop();
        for (int *a : dxdy) {
            int n_y = xy.first + a[0];
            int n_x = xy.second + a[1];
            if (n_y < 0 || n_y >= n || n_x < 0 || n_x >= m)
                continue;
            if (vec[n_y][n_x] == 'O' || vec[n_y][n_x] == 'P') {
                if (vec[n_y][n_x] == 'P')
                    ret++;
                vec[n_y][n_x] = 'X';
                q.push(std::make_pair(n_y, n_x));
            } 
        }
    }
    if (ret == 0)
        std::cout << "TT";
    else
        std::cout << ret;
}