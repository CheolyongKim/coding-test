#include <iostream>
#include <vector>
using namespace std;

// def
int N, r, c;
vector<vector<int>> grid;
void input();
void process();
void output();

void input(){
    cin >> N >> r >> c;
    grid.resize(N);
    for (int i=0; i<N; i++){
        grid.at(i).resize(N);
        for (int j=0; j<N; j++)
            cin >> grid.at(i).at(j);
    }
}

void process(){
    int dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1};
    r--; c--;
    bool flag = true;
    while (flag){
        output();
        for (int dir=0; dir<4; dir++){
            flag = false;
            int y=r+dy[dir], x=c+dx[dir];
            if (y<0 || y>=N || x<0 || x>=N) continue;
            if (grid.at(y).at(x) <= grid.at(r).at(c)) continue;
            r=y; c=x;
            flag = true;
            break;
        }
    }
}

void output(){
    cout << grid.at(r).at(c) << " ";
}

int main() {
    input();
    process();
    return 0;
}