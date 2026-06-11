#include <string>
#include <vector>
using namespace std;

// def
#define LL long long

vector<int> solution(int n, LL left, LL right) {
    /*
        1 2 3 4
        2 2 3 4
        3 3 3 4
        4 4 4 4
        
        i==2 || j==2 -> 3
        -> max(i,j)+1
        
        left/n -> i
        left%n -> j
        (right 동일)
    */
    vector<int> answer;
    
    for (LL idx = left; idx <= right; idx++){
        LL i = idx/(LL)n, j = idx%(LL)n;
        answer.push_back((i>j ? i:j)+1LL);
    }
    
    return answer;
}