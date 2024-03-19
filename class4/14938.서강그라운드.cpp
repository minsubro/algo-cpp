#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int inf = (~0U >> 2);

int main()
{
    int n, m, r; cin >> n >> m >> r;
    vector<int> item_cnt(n + 1);
    vector<vector<int> > dist(n + 1, vector<int>(n + 1, inf));
    for (int i = 1; i <= n; i++) {
        cin >> item_cnt[i];
    }
    for (int i = 0; i < r; i++) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (j == k) {
                    dist[j][k] = 0;
                }
                else
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m)
                tmp += item_cnt[j];
        }
        ret = max(ret, tmp);
    }
    cout << ret;
}