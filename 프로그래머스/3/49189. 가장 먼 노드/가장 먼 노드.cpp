#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> dist(n, 20000);
    vector<vector<int>> rel(n, vector<int>(0));
    queue<int> q;
    
    // 간선 정리
    for (vector<int> e : edge){
        int from = e.at(0)-1, to = e.at(1)-1;
        rel.at(from).push_back(to);
        rel.at(to).push_back(from);
    }
    
    // dijkstra
    dist.at(0) = 0;
    for (int neighbor : rel.at(0)) {
        q.push(neighbor);
        dist.at(neighbor) = dist.at(0)+1;
    }
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int neighbor : rel.at(cur)){
            if (dist.at(neighbor) > dist.at(cur)+1){
                dist.at(neighbor) = dist.at(cur)+1;
                q.push(neighbor);
            }
        }
    }
    
    int me = *max_element(dist.begin(), dist.end());
    int answer = 0;
    for (int d : dist)
        if (d == me)
            answer++;
    return answer;
}