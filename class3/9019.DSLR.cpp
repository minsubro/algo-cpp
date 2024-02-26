#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

int D(int n)
{
    return ((n * 2) % 10000);
}

int S(int n)
{
    if (n == 0)
        return (9999);
    return (n - 1);
}

int L(int n)
{
    int tmp = n / 1000;
    n %= 1000;
    return n * 10 + tmp;
}

int R(int n)
{
    int tmp = n / 10;
    return (n % 10 * 1000 + tmp);
}

int main()
{
    int t; std::cin >> t;
    for (t; t > 0; t--)
    {
        int a, b;
        std::cin >> a >> b;
        bool visit[10001] = {true,};
        memset(visit, 1, sizeof(bool) * 10001);
        std::queue<std::pair<int, std::string> > q;
        visit[a] = false;
        q.push(std::make_pair(a, std::string("")));
        while (true) {
            int x = q.front().first;
            std::string op = q.front().second;
            if (x == b) {
                std::cout << op << "\n";
                break ;
            }
            q.pop();
            int tmp = 0;
            tmp = D(x);
            if (visit[tmp]) {
                q.push(std::make_pair(tmp, op + "D"));
                visit[tmp] = false;
            }
            tmp = S(x);
            if (visit[tmp]) {
                q.push(std::make_pair(tmp, op + "S"));
                visit[tmp] = false;
            }
            tmp = L(x);
            if (visit[tmp]) {
                q.push(std::make_pair(tmp, op + "L"));
                visit[tmp] = false;
            }
            tmp = R(x);
            if (visit[tmp]) {
                q.push(std::make_pair(tmp, op + "R"));
                visit[tmp] = false;
            }
        }
    }
}