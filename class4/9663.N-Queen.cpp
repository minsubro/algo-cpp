#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(15);
int cnt, n;

bool checkArr(int low, int pos) {
    for (int i = 1; i <= low; i++) {
        if (pos == arr[low - i])
            return (false);
        if (pos == arr[low - i] - i || pos == arr[low - i] + i)
            return (false);
    }
    return (true);
}

void sol(int low) {
    for(int i = 0; i < n; i++) {
        arr[low] = i;
        if (low == n - 1 && checkArr(low, i))
            cnt += 1;
        else if (low != n - 1 && checkArr(low, i))
            sol(low + 1);
    }
}

int main()
{
    cin >> n;
    sol(0);
    cout << cnt;
}