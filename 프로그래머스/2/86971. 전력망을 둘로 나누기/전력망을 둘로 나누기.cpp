#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> new_wires;
vector<int> visited;

void visited_init(){
    visited.clear();
    visited.resize(101, false);
}

int dfs(int i){
    visited.at(i) = true;
    int sum = 1;
    
    auto new_wire = new_wires.at(i);
    for (int w : new_wire){
        if (visited.at(w)) continue;
        sum += dfs(w);    
    }
    return sum;
}

int solution(int n, vector<vector<int>> wires) {
    priority_queue<int> pq;

    for (int w=0; w<wires.size(); w++){
        // w: 자를 wires의 인덱스
        // wires 더 편하게 바꾸기
        new_wires.clear();
        new_wires.resize(n+1);
        for (int i=0; i<wires.size(); i++) 
            if (i != w) {
                new_wires.at(wires.at(i).at(0)).push_back(wires.at(i).at(1));
                new_wires.at(wires.at(i).at(1)).push_back(wires.at(i).at(0));
            }
        int a = 0, b = 0; // 두 트리의 노드 개수
        
        visited_init();
        
        for (int i=1; i<=n; i++){
            if (visited.at(i)) continue;
            if (a == 0){
                // 처음 dfs 시작했을 때
                a = dfs(i);
            }else if (b == 0){
                // 두 번째 트리를 dfs할 때
                b = dfs(i);
            }else{
                // 이미 두 트리를 모두 탐색했을 때
                break;
            }
        }
        pq.push(-abs(a-b));
    }
    
    return -pq.top();
}