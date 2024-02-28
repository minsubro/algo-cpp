#include <iostream>
#include <vector>

const int inf = (~0U>>2);

void InitArr(int **arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = inf;
        }
    }
}

int main()
{
    int n; std::cin >> n;
    int **graph = new int *[n];
    for (int i = 0; i < n; i++)
        graph[i] = new int[n];
    InitArr(graph, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            int x; std::cin >> x;
            if (x == 1)
                graph[i][j]= 1;
        }
    }
    for (int k = 0 ; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == inf) {
                std::cout << 0 << " ";
            }
            else
                std::cout << 1 << " ";
        }
        std::cout << "\n";
    }
}