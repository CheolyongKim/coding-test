#include <iostream>
#include <string>
using namespace std;

// def
string A;
int minimum;

void rshift(){
    char tail = A[A.length() - 1];
    for (int i=A.length()-1; i>0; i--) A[i]=A[i-1];
    A[0]=tail;
}

int RLE(string A){
    int rle = 0;

    while (A.length()>0){
        char head = A.at(0);
        while (!A.empty() && head == A.at(0)) {
            A.erase(0,1);
        }
        rle += 2;
    }
    return rle;
}

void input(){
    cin >> A;
}

void process(){
    minimum = 11;

    // x*10
    bool flag = true;
    for (int i=1; i<A.length(); i++)
        if (A[i]!=A[i-1]) flag = false;
    if (flag && A.length()==10){
        minimum = 3;
        return;
    }

    // process
    for (int i=0; i<A.length(); i++){
        minimum = min(minimum, RLE(A));
        rshift();
    }
}

void output(){
    cout << minimum;
}

int main() {
    input();
    process();
    output();
    return 0;
}