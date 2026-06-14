#include <iostream>
#include <deque>
using namespace std;

// def
int N, T, temp;
deque<int> D[3];

int main() {
    // input
    cin >> N >> T;
    for (int i=0; i<3; i++)
        for (int j = 0; j < N; j++) {
            cin >> temp;
            D[i].push_back(temp);
        }

    // process
    T %= N * 3;
    while (T > 0) {
        for (int i = 0; i < 3; i++) {
            D[(i + 1) % 3].push_front(D[i].back());
            D[i].pop_back();
        }
        T--;
    }

    // output
    for (int i = 0; i < 3; i++) {
        for (int q : D[i])
            cout << q << " ";
        cout << endl;
    }

    return 0;
}