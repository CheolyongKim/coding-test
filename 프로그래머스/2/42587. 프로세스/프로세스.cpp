#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    while (1){
        if (priorities.empty()) {
            break;
        }
        int max_p = *max_element(priorities.begin(), priorities.end());
        
        if (priorities.at(0) == max_p){
            answer++;
            if (location == 0) break;
            else {
                priorities.erase(priorities.begin());
                location = (location + priorities.size() - 1) % priorities.size();
            }
        }
        else{
            int temp = priorities.at(0);
            priorities.erase(priorities.begin());
            priorities.push_back(temp);
            location = (location + priorities.size() - 1) % priorities.size();
        }
    }
    
    return answer;
}