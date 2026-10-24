#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    multiset<int> ms;
    for (string op : operations){
        if (op[0] == 'I'){
            ms.insert(stoi(op.substr(2)));
        }
        else if (op[0] == 'D'){
            if (ms.empty()) continue;
            if (op[2] == '1'){
                ms.erase(prev(ms.end()));
            }
            else if (op[2] == '-'){
                ms.erase(ms.begin());
            }
        }
    }
    
    if (ms.empty()){
        answer = {0, 0};
    }
    else{
        answer.push_back(*prev(ms.end()));
        answer.push_back(*ms.begin());
    }
    
    return answer;
}