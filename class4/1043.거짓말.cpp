#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int main()
{
    int n, m; std::cin >> n >> m;
    int tmp; std::cin >> tmp;
    std::vector<int> v(tmp);
    std::vector<int> graph[n + 1];
    std::queue<int> q;
    std::vector<int> partyInfo[m];
    bool visit[51][51];
    std::fill(&visit[0][0], &visit[50][51], true);
    for (int i = 0; i < tmp; i++) {
        std::cin >> v[i];
        q.push(v[i]);
    }
    for (int i = 0; i < m; i++) {
        std::cin >> tmp;
        partyInfo[i] = std::vector<int> (tmp);
        for (int j = 0; j < tmp; j++) {
            std::cin >> partyInfo[i][j];
        }
        for (int j = 0; j < tmp; j++) {
            for (int k = j + 1; k < tmp; k++) {
                graph[partyInfo[i][j]].push_back(partyInfo[i][k]);
                graph[partyInfo[i][k]].push_back(partyInfo[i][j]);
            }
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (size_t i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if (visit[now][next] && visit[next][now]) {
                visit[now][next] = false;
                visit[next][now] = false;
                q.push(next);
                v.push_back(next);
            }
        }
    }
    int ret = m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < partyInfo[i].size(); j++) {
            if (std::find(v.begin(), v.end(), partyInfo[i][j]) != v.end()) {
                ret -= 1;
                break ;
            }
        }
    }
    std::cout << ret;
}