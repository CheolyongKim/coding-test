#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

/*
    n <- natural number
    k <- natural number & 0

    even
    ---
    n n+1 n+2 ... n+2k+1 -> (2k+2)*n + (k+1)*(2k+1) = (k+1)(2n+2k+1)
    -> 2(k+1)m + (k+1)(2k+1) = n
    -> m = {n - (k+1)(2k+1)}/2(k+1)
    
    odd
    ---
    n n+1 n+2 ... n+2k -> (2k+1)*n + k*(2k+1) = (2k+1)(n+k)
    -> (2k+1)m + k(2k+1) = n
    -> m = {n - k(2k+1)}/(2k+1)
*/

int solution(int n) {
    int answer = 0;
    
    for (float k = 0; k < sqrt(n); k++){
        float x = (n - (k+1)*(2*k+1))/((2*k+2)); // even
        float y = (n - k*(2*k+1))/(2*k+1); // odd
        if (x > 0 && floor(x) == x) {
            //cout << "even - " << k << "\n";
            //cout << "x is " << x << "\n";
            answer++;
        }
        if (y > 0 && floor(y) == y) {
            //cout << "odd - " << k << "\n";
            answer++;
        }
    }
    
    return answer;
}