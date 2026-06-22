#include <string>
#include <vector>
#include <cmath>
using namespace std;
/*
    문제이해
    output: 각 배포마다 몇 개의 기능이 배포되는지의 배열
    input: 지금까지의 진행상황 & 개발속도/일 (index가 곧 배포되어야 하는 순서)
    
    시간복잡도
    BF: ?
    
    예시 2
    -> 먼저 모든 기능에 대해 끝나기까지 며칠이 걸리는지 계산
    -> 대충 앞에서부터 ... ~~이상 나올때까지 ... 개수세는 ..느낌.. .?
*/

// def
int n;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    n = progresses.size();
    vector<int> time_taken;
    time_taken.resize(n);
    
    // fill time_taken
    for (size_t i=0 ; i<n; i++){
        time_taken.at(i) = ceil((float)(100-progresses.at(i)) / speeds.at(i));
    }
    
    // process
    int inc = -1;
    for (size_t i=0; i<n; i++){
        if (time_taken.at(i) > inc){
            inc = time_taken.at(i);
            answer.push_back(1);
        } else {
            if (answer.empty()) answer.push_back(0);
            answer.back()++;
        }
    }
    
    return answer;
}