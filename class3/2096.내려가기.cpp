#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    int max[3] = {a, b, c};
    int min[3] = {a, b, c};
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        int tmp1, tmp2, tmp3;
        tmp1 = a + std::max(max[0], max[1]);
        tmp2 = b + std::max(max[0], std::max(max[1], max[2]));
        tmp3 = c + std::max(max[1], max[2]);
        max[0] = tmp1; max[1] = tmp2; max[2] = tmp3;
        tmp1 = a + std::min(min[0], min[1]);
        tmp2 = b + std::min(min[0], std::min(min[1], min[2]));
        tmp3 = c + std::min(min[1], min[2]);
        min[0] = tmp1; min[1] = tmp2; min[2] = tmp3;
    }
    std::cout << std::max(max[0], std::max(max[1], max[2])) << " "
        << std::min(min[0], std::min(min[1], min[2]));
}
