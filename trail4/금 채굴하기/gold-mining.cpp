#include <iostream>
#include <queue>
using namespace std;

// def
int N, M;
int gold[20][20];
#define COST(K) K*K + (K+1)*(K+1)
#define REVENUE(M, num) M*num
priority_queue<int> pq;
int di[4] = { 0,1,0,-1 }, dj[4] = { 1,0,-1,0 };

// function
bool isOOB(int i, int j) {
    return i < 0 || j < 0 || i >= N || j >= N;
}

int checkThenReturn(int i, int j) {
    return isOOB(i, j) ? 0 : gold[i][j];
}

int mineGold(int i, int j, int K) {
    if (K == 0) return gold[i][j];
    int goldNum = 0;
    for (int dir = 0; dir < 4; dir++) {
        for (int r = 0; r < K; r++)
            goldNum += checkThenReturn(i + di[dir]*(K-r) + di[(dir+1)%4]*r, j + dj[dir]*(K-r) + dj[(dir+1)%4]*r);
    }
    return goldNum + mineGold(i, j, K - 1);
}

bool isProfittable(int revenue, int cost) {
    return revenue >= cost;
}

int main() {
    /*
        N=1 -> K=0
        N=2 -> K=~2
        N=3 -> K=~2
        N=4 -> K=~4
        N=5 -> K=~4
        N=6 -> K=~6
        N=7 -> K=~6
        N=8 -> K=~8
        K = 2*(N/2) -> all area covered
    */

    /*
        K=0 -> (0~N-1) * (0~N-1)
        K=1 -> ``
        K=2 -> ... 대충 귀찮으니 완탐 O(N^3) - 해도 괜찮음
    */

    // input
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> gold[i][j];

    // process
    for (int K = 0; K <= 2 * (N / 2); K++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // i,j = center
                int goldNum = mineGold(i, j, K);
                if (isProfittable(REVENUE(M, goldNum), COST(K))) pq.push(goldNum);
            }
        }
    }

    // output
    cout << pq.top();

    return 0;
}