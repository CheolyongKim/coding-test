#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int a = wallet.at(0), b = wallet.at(1);
    int c = bill.at(0), d = bill.at(1);
    
    while (!(c<=a && d<=b) && !(c<=b && d<=a)){
        if (c > d) c /= 2;
        else d /= 2;
        answer++;
    }
    
    return answer;
}