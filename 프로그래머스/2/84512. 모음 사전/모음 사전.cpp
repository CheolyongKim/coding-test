#include <string>
#include <vector>
using namespace std;
/*
    A,B 3자리
    A
    AA
    AAA
    AAB
    AB
    ABA
    ABB
    B
    BA
    BAA
    BAB
    BB
    BBA
    BBB
*/
const int n = 5;

int f(char c){
    switch(c){
        case 'A': return 0;
        case 'E': return 1;
        case 'I': return 2;
        case 'O': return 3;
        case 'U': return 4;
    }
    return -1;
}

int count(int pos){
    int pow = n-pos-1;
    int ret = 1;
    while (pow > 0){
        ret = 1 + n*ret;
        pow--;
    }
    return ret;
}

int solution(string word) {
    int answer = 0;
    
    for (int i=0; i<word.length(); i++){
        int c = f(word[i]);
        answer += 1 + c * count(i);
    }
    
    return answer;
}