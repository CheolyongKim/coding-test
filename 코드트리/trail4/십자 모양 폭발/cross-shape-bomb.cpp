#include <iostream>
#include <vector>
using namespace std;

// def
int N;
vector<vector<int>> grid;
int r,c;

void input(){
    cin >> N;
    grid.resize(N);
    for (int i=0; i<N; i++){
        grid.at(i).resize(N);
        for (int j=0; j<N; j++)
            cin >> grid.at(i).at(j);
    }
    cin >> r >> c;
}

bool is_OOB(int y, int x){
    return y<0 || y>=N || x<0 || x>=N;
}

void process(){
    // bomb
    vector<int> dy={0,1,0,-1}, dx={1,0,-1,0};
    int power = grid.at(r-1).at(c-1);
    for (int p=0; p<power; p++)
        for (int dir=0; dir<4; dir++){
            int y=r-1+dy.at(dir)*p, x=c-1+dx.at(dir)*p;
            if (is_OOB(y,x)) continue;
            grid.at(y).at(x) = 0;
        }

    // gravity
    vector<vector<int>> temp;
    temp.resize(N);
    for (int i=0; i<N; i++) temp.at(i).resize(N,0);

    for (int col=0; col<N; col++){
        int stack_row = N-1;
        for (int row=N-1; row>=0; row--){
            if (grid.at(row).at(col)==0) continue;
            temp.at(stack_row--).at(col) = grid.at(row).at(col);
        }
    }
    grid.assign(temp.begin(), temp.end());
}

void output(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            cout << grid.at(i).at(j) << " ";
        cout << "\n";
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}