#include <iostream>
#include <vector>

using namespace std;
const int inf = (~0U >> 2);

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int> > dist(n + 1, vector<int>(n + 1, inf));
    vector<vector<pair<int, int> > > graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (j == k)
                    dist[j][k] = 0;
                else
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] >= inf)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}