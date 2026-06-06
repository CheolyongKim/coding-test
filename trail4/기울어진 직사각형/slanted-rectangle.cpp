#include <iostream>
#include <queue>

using namespace std;

// def
priority_queue<int> pq;
int n;
int grid[20][20];

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
        기울어진 직사각형이 아니라 안기울어진 직사각형처럼 이중 for문을 돌릴 수 있으면
        훨씬 편할텐데... 라는 생각으로
        N=3 -> 2*2
        N=4 -> 2*(2,3), 3*(2)
        N=5 -> 2*(2,3,4), 3*(2,3), 4*(2)
        ...
    */
    for (int w=2; w<n; w++){
        for (int h=2; h<n+2-w; h++){
            int sum=0;
            int y_begin, x_begin;
            for (int i=0; i<w-1; i++){
                y_begin = w-1; x_begin = 0;
                sum += grid[y_begin - i][x_begin + i];
                sum += grid[y_begin - (w-1) + (h-1) + i][x_begin + (w-1) + (h-1) - i];
            }
            for (int i=0; i<h-1; i++){
                y_begin = 0; x_begin = w-1;
                sum += grid[y_begin + i][x_begin + i];
                sum += grid[y_begin + (w-1) + (h-1) - i][x_begin + (h-1) - (w-1) - i];
            }
            pq.push(sum);
        }
    }

    // output
    if (pq.empty()) pq.push(0);
    cout << pq.top();

    return 0;
}
