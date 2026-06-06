#include <iostream>
#include <queue>

using namespace std;

// 반례
/*
5
1 1 1 1 1
1 3 1 1 1
3 1 9 1 1
1 3 1 3 1
1 1 3 1 1

20 (X)
24 (O)

N=5 -> 2*(2,3,4),
    -> 2*(2,3)*2, 3*(2,3)
    -> 2*(2)*3, ...
*/

// def
priority_queue<int> pq;
int n;
int grid[20][20];

bool isCorrectShape(int wi, int wj, int ei, int ej){
    if ((wi+wj)%2 != (ei+ej)%2) return false;
    if ((wi-wj)==(ei-ej) || (wi+wj)==(ei+ej)) return false;
    return true;
}
int calculateSum(int wi, int wj, int ei, int ej) {
    int sum = 0;
    int i=wi, j=wj;
    // west->north
    while ((i-j)!=(ei-ej)){
        sum += grid[i--][j++];
    }
    // north->east
    while (i!=ei || j!=ej) {
        sum += grid[i++][j++];
    }
    // east->south
    while ((i-j) != (wi-wj)) {
        sum += grid[i++][j--];
    }
    // south->west
    while (i!=wi || j!=wj) {
        sum += grid[i--][j--];
    }      
    return sum;
}

int main() {
    // input
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // process
    /*
        그냥 가장 서쪽 점 하나 가장 동쪽 점 하나 잡고
        기울어진 직사각형이 만족되면 합계 계산
        이게 더 완탐의 취지에 맞고 간단할듯
    */
    for (int west_i=1; west_i<n-1; west_i++)
        for (int west_j=0; west_j<n-2; west_j++)
            for (int east_i=1; east_i<n-1; east_i++)
                for (int east_j=west_j+2; east_j<n; east_j++)
                    if (isCorrectShape(west_i, west_j, east_i, east_j)) 
                        pq.push(calculateSum(west_i, west_j, east_i, east_j));

    // output
    if (pq.empty()) pq.push(0);
    cout << pq.top();

    return 0;
}
