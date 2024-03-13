#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int recv(int s, vector<vector<pair<int, int> > > &tree, int &ret) {
    if (tree[s].size() == 0) 
        return (0);
    vector<int> value(tree[s].size() + 1, 0);
    for (int i = 0; i < tree[s].size(); i++) {
       tree[s][i].second += recv(tree[s][i].first, tree, ret);
       value[i] = tree[s][i].second;
    }
    sort(value.begin(), value.end(), greater<>());    
    ret = max(ret, value[0] + value[1]);
    return (value[0]);
}

int main()
{
    int n; cin >> n;
    vector<vector<pair<int, int> > > tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int parent, child, value; cin >> parent >> child >> value;
        tree[parent].push_back(make_pair(child, value));
    }
    int ret = 0;
    recv(1, tree, ret);
    cout << ret;
}