#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n;
vector<vector<char> > map(10000, vector<char> (10000, ' '));

void sol(int x, int y, int n)
{
    if (n == 3) {
        map[y][x] = '*';
        map[y + 1][x - 1] = map[y + 1][x + 1] = '*';
        map[y + 2][x - 1] = map[y + 2][x - 2] = map[y + 2][x] = map[y + 2][x + 1] = map[y + 2][x + 2] = '*';
    }
    else {
        sol(x, y, n / 2);
        sol(x - n / 2, y + n / 2, n / 2);
        sol(x + n / 2, y + n / 2, n / 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    sol(n - 1, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    } 
}