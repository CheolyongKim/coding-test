#include <iostream>
#include <queue>
using namespace std;

// def
priority_queue<int> pq;
int N, M;
// 동, 서, 남, 북
int dy[4] = { 0,0,1,-1 }, dx[4] = { 1,-1,0,0 };
int A[200][200];

bool isOOB(int y, int x) {
    return y < 0 || x < 0 || y >= N || x >= M;
}

void insertLshapedSums(int i, int j) {
    for (int dir = 0; dir < 4; dir++) {
        // out of bound check
        int y0 = i + dy[dir], x0 = j + dx[dir];
        int y1 = i + dy[(dir + 1) % 4], x1 = j + dx[(dir + 1) % 4];
        if (isOOB(y0, x0) || isOOB(y1, x1)) continue;

        // then insert
        pq.push(A[i][j] + A[y0][x0] + A[y1][x1]);
    }
}

void insertIshapedSums(int i, int j) {
    for (int dir = 0; dir < 4; dir++) {
        // out of bound check
        int y0 = i + 2 * dy[dir], x0 = j + 2 * dx[dir];
        if (isOOB(y0, x0)) continue;

        // then insert
        int x = A[i][j] + A[i + dy[dir]][j + dx[dir]] + A[y0][x0];
        pq.push(x);
    }
}

void insertSumsByRootCell(int i, int j) {
    insertLshapedSums(i, j);
    insertIshapedSums(i, j);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];



    // for loop
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            insertSumsByRootCell(i, j);

    // answer
    cout << pq.top();

    return 0;
}