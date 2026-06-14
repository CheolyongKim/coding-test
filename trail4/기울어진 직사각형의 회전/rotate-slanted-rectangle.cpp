#include <iostream>
#include <vector>
using namespace std;

// def
int N;
vector<vector<int>> G;
int r,c,m1,m2,m3,m4,dir;

void input(){
    cin >> N;
    G.resize(N);
    for (int i=0; i<N; i++){
        G.at(i).resize(N);
        for (int j=0; j<N; j++)
            cin >> G.at(i).at(j);
    }
}

void process(){
    // process input
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    // push
    int i=r-1, j=c-1;
    int head = G.at(i).at(j);
    if (dir==0){
        for (; m4>0; m4--) G.at(i--).at(j--) = G.at(i-1).at(j-1);
        for (; m3>0; m3--) G.at(i--).at(j++) = G.at(i-1).at(j+1);
        for (; m2>0; m2--) G.at(i++).at(j++) = G.at(i+1).at(j+1);
        for (; m1>0; m1--) G.at(i++).at(j--) = G.at(i+1).at(j-1);
        G.at(--i).at(++j) = head;
    }else if (dir==1){
        for (; m1>0; m1--) G.at(i--).at(j++) = G.at(i-1).at(j+1);
        for (; m2>0; m2--) G.at(i--).at(j--) = G.at(i-1).at(j-1);
        for (; m3>0; m3--) G.at(i++).at(j--) = G.at(i+1).at(j-1);
        for (; m4>0; m4--) G.at(i++).at(j++) = G.at(i+1).at(j+1);
        G.at(--i).at(--j) = head;
    }
}

void output(){
    for (auto row : G){
        for (int cell : row)
            cout << cell << " ";
        cout << "\n";
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}