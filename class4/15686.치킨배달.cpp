#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
vector<pair<int, int> > chicken, house;
int ret = (~0U >> 1);

int cal(vector<pair<int, int> > tmp) {
    int sum = 0;

    for (int i = 0; i < house.size(); i++) {
        int _min = (~0U >> 1);
        for (int j = 0; j < tmp.size(); j++) {
            _min = min(_min, abs(tmp[j].first - house[i].first) + abs(tmp[j].second - house[i].second));
        }
        sum += _min;
    }
    return (sum);
}

void recv(int s, int deep, vector<pair<int ,int> > &choice, int m) {
    for (int i = s; i < chicken.size(); i++) {
        choice[deep] = chicken[i];
        if (deep == m - 1) {
            ret = min(ret, cal(choice));
        }
        else
            recv(i + 1, deep + 1, choice, m);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x == 1) {
                house.push_back({i, j});
            }
            else if (x == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    vector<pair<int, int> >tmp(m);
    recv(0, 0, tmp, m);
    cout << ret;
}