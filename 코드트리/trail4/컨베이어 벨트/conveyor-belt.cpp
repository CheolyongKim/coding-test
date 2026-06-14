#include <iostream>
#include <deque>
using namespace std;

// def
int N, T, temp;
deque<int> Q1, Q2;

int main() {
    // input
    cin >> N >> T;
    for (int i = 0; i < N * 2; i++) {
        cin >> temp;
        i / N == 0 ? Q1.push_back(temp) : Q2.push_back(temp);
    }

    // process
    T %= N * 2;
    while (T > 0) {
        Q2.push_front(Q1.back());
        Q1.pop_back();
        Q1.push_front(Q2.back());
        Q2.pop_back();
        T--;
    }
    
    // output
    for (int q : Q1) cout << q << " ";
    cout << endl;
    for (int q : Q2) cout << q << " ";

    return 0;
}