#include <iostream>
#include <vector>
using namespace std;

// def
int N;
vector<int> jenga;
int s1,e1,s2,e2;

void input(){
    cin >> N;
    jenga.resize(N);
    for (int i=0; i<N; i++) cin >> jenga.at(i);
    cin >> s1 >> e1 >> s2 >> e2;
}

void process(){
    jenga.erase(jenga.begin()+s1-1, jenga.begin()+e1);
    jenga.erase(jenga.begin()+s2-1, jenga.begin()+e2);
}

void output(){
    cout << jenga.size() << "\n";
    for (int j : jenga) cout << j << "\n";
}

int main() {
    input();
    process();
    output();
    return 0;
}