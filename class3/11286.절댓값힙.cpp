#include <iostream>
#include <queue>
#include <cstdlib>

struct Compare {
    bool operator() (int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::priority_queue<int, std::vector<int>, Compare > pq;
    int n; std::cin >> n;
    for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
        if (x != 0) {
            pq.push(x);
        }
        else {
            if (pq.empty())
                std::cout << 0 << "\n";
            else {
                std::cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}