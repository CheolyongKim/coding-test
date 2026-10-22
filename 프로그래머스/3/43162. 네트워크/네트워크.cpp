#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++){
        if (!visited.at(i)){
            // bfs
            queue<int> q;
            q.push(i);
            visited.at(i) = true;
            
            while (!q.empty()){
                int cur = q.front();
                q.pop();
                for (int j = 0; j < n; j++){
                    int is_neighbor = computers.at(cur).at(j);
                    if (is_neighbor && !visited.at(j)){
                        q.push(j);
                        visited.at(j) = true;
                    }
                }
            }
            
            answer++;
        }
    }
    
    return answer;
}