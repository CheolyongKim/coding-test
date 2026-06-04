#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // brown/2 = 가로 + 세로 - 2 = a+b-2 // a>=b // brown = 2a+2b-4
    // yellow = (가로-2)*(세로-2)
    // a, b >= 3
    //double d;
    int a;
    for (int b = 3; b<=(a=(brown-2*b+4)/2); b++){
        
        // if ((int)d != d) break;
        // else a = d;
        if (yellow == (a-2)*(b-2)){
            answer.push_back(a);
            answer.push_back(b);
            break;
        }
    }
    
    return answer;
}