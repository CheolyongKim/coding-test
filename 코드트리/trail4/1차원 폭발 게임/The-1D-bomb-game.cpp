#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

// def
int N,M;
vector<int> bombs;

bool explode(){
    bool is_exploded = false;

    // scan
    vector<array<int, 3>> bombs_info;  // num, start_index, end_index
    for (int i=0; i<bombs.size(); i++){
        if (bombs_info.empty()) bombs_info.push_back({bombs.at(i), i, i});
        else if (bombs.at(i) == bombs_info.back()[0]) bombs_info.back()[2]++;
        else bombs_info.push_back({bombs.at(i), i, i});
    }

    // explode
    for (auto info : bombs_info){
        if (info[2]-info[1]+1 >= M){
            fill(bombs.begin()+info[1], bombs.begin()+info[2]+1, 0);
            is_exploded = true;
        }
    }

    // gravity
    bombs.erase(remove(bombs.begin(), bombs.end(), 0), bombs.end());

    return is_exploded;
}

void process(){
    while (explode()) {}
}

void input(){
    cin >> N >> M;
    bombs.resize(N);
    for (size_t i=0; i<N; i++) cin >> bombs.at(i);
}

void output(){
    cout << bombs.size() << "\n";
    for (size_t bomb : bombs) cout << bomb << "\n";
}

int main() {
    input();
    process();
    output();
    return 0;
}