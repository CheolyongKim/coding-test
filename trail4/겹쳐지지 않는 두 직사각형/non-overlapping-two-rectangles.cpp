#include <iostream>
#include <queue>
using namespace std;

// def
priority_queue<int> pq;
int N, M;
int grid[5][5];

int main() {
    // input
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];
    
    // process
    for (int i1=0; i1<N; i1++)
        for (int j1=0; j1<M; j1++)
            for (int w1=1; w1<=M-j1; w1++)
                for (int h1=1; h1<=N-i1; h1++)
                    for (int i2 = 0; i2 < N; i2++)
                        for (int j2 = 0; j2 < M; j2++)
                            for (int w2 = 1; w2 <= M - j2; w2++)
                                for (int h2 = 1; h2 <= N - i2; h2++) {
                                    if (
                                        !(
                                            // 세로 안겹침
                                            ((i1 + h1 - 1 < i2) || (i2 + h2 - 1) < i1)
                                            ||
                                            // 가로 안겹침
                                            ((j1 + w1 - 1 < j2) || (j2 + w2 - 1) < j1)
                                            )
                                        ) continue;
                                    int sum = 0;
                                    for (int i01 = i1; i01 < i1 + h1; i01++)
                                        for (int j01 = j1; j01 < j1 + w1; j01++)
                                            sum += grid[i01][j01];
                                    for (int i02 = i2; i02 < i2 + h2; i02++)
                                        for (int j02 = j2; j02 < j2 + w2; j02++)
                                            sum += grid[i02][j02];
                                    pq.push(sum);
                                }
                    

    // output
    cout << pq.top();
    return 0;
}