#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// def
int N, M, Q, r1, c1, r2, c2;
vector<vector<int>> B;

void print(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cout << B.at(i).at(j) << " ";
        cout << "\n";
    }
}

void push() {
    int i=r1-1, j=c1-1;
    int head = B.at(i).at(j);

    while (i < r2-1) B.at(i++).at(j) = B.at(i+1).at(j);
    while (j < c2-1) B.at(i).at(j++) = B.at(i).at(j+1);
    while (i > r1-1) B.at(i--).at(j) = B.at(i-1).at(j);
    while (j > c1-1) B.at(i).at(j--) = B.at(i).at(j-1);
    B.at(i).at(j+1) = head;
}

bool isOOB(int y, int x) {
    return y < 0 || y >= N || x < 0 || x >= M;
}

void normalize() {
    int dy[5] = { 0,0,1,0,-1 }, dx[5] = { 0,1,0,-1,0 };
    vector<vector<int>> avg(B);
    for (int i = r1 - 1; i < r2; i++) {
        for (int j = c1 - 1; j < c2; j++) {
            int sum = 0, div = 0;
            for (int dir=0; dir < 5; dir++) {
                int y = i + dy[dir], x = j + dx[dir];
                if (isOOB(y, x)) continue;
                sum += B.at(y).at(x);
                div++;
            }
            avg.at(i).at(j) = floor(sum / div);
        }
    }
    for (int i = r1 - 1; i < r2; i++)
        for (int j = c1 - 1; j < c2; j++)
            B.at(i).at(j) = avg.at(i).at(j);
}

void process() {
    push();
    normalize();
}

int main() {
    // input
    cin >> N >> M >> Q;
    B.resize(N);
    for (int i = 0; i < N; i++) {
        B.at(i).resize(M);
        for (int j = 0; j < M; j++) {
            cin >> B.at(i).at(j);
        }
    }

    // process
    for (;Q > 0;Q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        process();
    }

    // output
    print();    

    return 0;
}