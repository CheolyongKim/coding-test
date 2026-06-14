#include <iostream>
#include <queue>
using namespace std;

// def
priority_queue<int> pq;
int N, M;
int grid[20][20];

int main() {
    // input
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];

    // process
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            for (int h=1; h<=N-i; h++)
                for (int w = 1; w <= M - j; w++) {
                    bool flag = true;
                    for (int y = i; y < i + h; y++)
                        for (int x = j; x < j + w; x++)
                            if (grid[y][x] <= 0) flag = false;
                    if (flag) pq.push(w * h);
                }

    // output
    if (pq.empty()) pq.push(-1);
    cout << pq.top();
    return 0;
}