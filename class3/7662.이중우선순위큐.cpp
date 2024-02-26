#include <iostream>
#include <queue>
#include <map>
#include <functional>

int main()
{
    int t; std::cin >> t;
    
    for(t; t > 0; t--) {
        std::multimap<int, int> map;
        int x; std::cin >> x;
        for(int i = 0; i < x; i++) {
            char oper; std::cin >> oper;
            int num; std::cin >> num;
            if (oper == 'I')
                map.insert(std::make_pair(num, 1));
            else if (oper == 'D' && !map.empty()) {
                if (num == 1) {
                    map.erase(--map.end());
                }
                else if (num == -1) {
                    map.erase(map.begin());
                }
            }
        }
        if (map.empty())
            std::cout << "EMPTY\n";
        else
            std::cout << (--map.end())->first << " " << map.begin()->first << "\n";
    }
    
}