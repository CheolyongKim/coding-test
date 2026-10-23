#include <string>
#include <vector>
#include <queue>

using namespace std;

bool can_convert(string a, string b){
    int count = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i]) count++;
    
    return count == 1;
}

int solution(string begin, string target, vector<string> words) {
    // words into relationships
    int n = words.size();
    vector<vector<bool>> rel(n, vector<bool>(n, false));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (can_convert(words.at(i), words.at(j))){
                rel.at(i).at(j) = rel.at(j).at(i) = true;
            }
        }
    }
    
    // search
    vector<int> dist(n, n+1);
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (can_convert(begin, words.at(i))){
            q.push(i);
            dist.at(i) = 1;
        }
    }
    
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        
        if (words.at(cur) == target){
            return dist.at(cur);
        }
        
        for (int i = 0; i < n; i++){
            if (rel.at(cur).at(i) && dist.at(i) > dist.at(cur)+1){
                q.push(i);
                dist.at(i) = dist.at(cur) + 1;
            }
        }
    }
    
    return 0;
}