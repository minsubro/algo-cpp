#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int BSearch(vector<int> &vec, int len, int target) {
    int left = 0;
    int right = len - 1;

    while (true) {
        int mid = (left + right) / 2;
        if (target == vec[mid])
            return (mid);
        if (target < vec[mid])
            right = mid - 1;
        else if (target > vec[mid])
            left = mid + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> vec;
    vector<int> tmp_vec;
    map<long long, int> map;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        vec.push_back(x);
        tmp_vec.push_back(x);
    }
    sort(tmp_vec.begin(), tmp_vec.end());
    auto uit = unique(tmp_vec.begin(), tmp_vec.end());
    tmp_vec.erase(uit, tmp_vec.end());
    for (int i = 0; i < n; i++) {
        cout << BSearch(tmp_vec, tmp_vec.size(), vec[i]) << " ";
    }
}