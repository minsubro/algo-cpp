#include <iostream>
#include <map>

using namespace std;

int main()
{
    string name, type;
    int tc; cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        int n; cin >> n;
        if (n == 0) {
            cout << 0 << "\n";
            continue ;
        }
        int ret = 1;
        map<string, int> map;
        for(int i = 0; i < n; i++) {
            cin >> name >> type;
            map[type]++;
        }
        for(auto it = map.begin(); it != map.end(); it++) {
            ret *= (it->second + 1);
        }
        cout << ret - 1 << "\n";
    }
}