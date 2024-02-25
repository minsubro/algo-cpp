#include <iostream>
#include <stack>

using namespace std;

int main() 
{
    stack<int> st;
    int n, k;
    int ret = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        st.push(x);
    }
    while(!st.empty()) {
        int cost = st.top();
        st.pop();
        if (k / cost > 0) {
            ret += k / cost;
            k %= cost;
        }
    }
    cout << ret;
}