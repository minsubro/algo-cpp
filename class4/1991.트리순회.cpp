#include <iostream>
#include <vector>
#include <map>

using namespace std;

string ret[3];

void traversal(std::map<string, pair<string, string> > &map, string node) {

    ret[0] += node;
    if (map[node].first != ".")
        traversal(map, map[node].first);
    ret[1] += node;
    if (map[node].second != ".")
        traversal(map, map[node].second);
    ret[2] += node;
}

int main()
{
    std::map<string, pair<string, string> > map;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string root, left, right; cin >> root >> left >> right;
        map.insert({root, {left, right}});
    }
    traversal(map, "A");
    for(int i = 0; i < 3; i++) {
        cout << ret[i] << "\n";
    }
}