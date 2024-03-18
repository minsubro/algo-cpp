#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

bool compare(string &s1, string &s2, int len)
{
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[len - i - 1])
            return (false);
    }
    return (true);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str, del; cin >> str >> del;
    stack<char> st;
    size_t del_len = del.size();
    for (size_t i = 0; i < str.size(); i++) {
        st.push(str[i]);
        if (str[i] == del[del_len - 1] && st.size() >= del_len) {
            string tmp;
            for (size_t j = 0; j < del_len; j++) {
                tmp.push_back(st.top());
                st.pop();
            }
            if (!compare(del, tmp, del_len)) {
                for (size_t j = 0; j < del_len; j++) {
                    st.push(tmp[del_len - j - 1]);
                }
            }
        }
    }
    
    if (st.size() == 0)
        cout << "FRULA";
    else {
        string tmp;
        while (!st.empty()) {
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp;
    }
}