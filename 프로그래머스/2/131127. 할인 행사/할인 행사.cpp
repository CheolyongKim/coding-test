#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int w = want.size(), d = discount.size();
    // 100000 * 10 * 10 -> 10000000 (ㄱㅊ)
    for (int i=0; i<d; i++){
        vector<int> copy;
        for (int n : number) copy.push_back(n);
        for (int j=0; j<w; j++){
            for (int k=0; k<10; k++){
                if (i+k >= d) continue;
                if (discount[i+k]==want[j]) copy[j]--;
            }
        }
        bool isAnswer = true;
        for (int c : copy)
            if (c > 0) isAnswer = false;
        if (isAnswer) answer++;
    }
    return answer;
}