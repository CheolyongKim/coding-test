#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int grid[20][20];

int calculateSumIn3by3(int i, int j){
    int sum = 0;
    for (int ip=i; ip<i+3; ip++)
        for (int jp=j; jp<j+3; jp++)
            sum += grid[ip][jp];
    return sum;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // def
    priority_queue<int> pq;

    // search
    for (int i=0; i<N-2; i++)
        for (int j=0; j<N-2; j++)
            pq.push(calculateSumIn3by3(i,j));

    // answer
    cout << pq.top();

    return 0;
}
