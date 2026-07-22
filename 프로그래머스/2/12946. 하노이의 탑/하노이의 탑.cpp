#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    if (n==1){
        vector<int> ans = {1,3};
        answer.push_back(ans);
        return answer;
    }
    
    // n-1: [1] => [2]
    vector<vector<int>> temp1 = solution(n-1);
    for (int i = 0; i < temp1.size(); i++){
        for (int j = 0; j < 2;  j++){
            if (temp1.at(i).at(j) == 2) temp1.at(i).at(j) = 3;
            else if (temp1.at(i).at(j) == 3) temp1.at(i).at(j) = 2;
        }
    }
    for (auto t : temp1) answer.push_back(t);
    
    // 1 => [3]
    vector<int> temp2 = {1,3};
    answer.push_back(temp2);
    
    // n-1: [2] => [3]
    vector<vector<int>> temp3 = solution(n-1);
    for (int i = 0; i < temp3.size(); i++){
        for (int j = 0; j < 2;  j++){
            if (temp3.at(i).at(j) == 1) temp3.at(i).at(j) = 2;
            else if (temp3.at(i).at(j) == 2) temp3.at(i).at(j) = 1;
        }
    }
    for (auto t : temp3) answer.push_back(t);
    
    return answer;
}