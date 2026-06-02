#include <iostream>
using namespace std;

// def
int R, C;
char board[15][15];

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> board[i][j];
    
    int answer = 0;
    bool startW = board[0][0] == 'W' ? true : false;
    // WBWB / BWBW

    for (int i = 1; i < R - 2; i++) {
        for (int j = 1; j < C - 2; j++) {
            if (board[i][j] == (startW ? 'B' : 'W')) {
                for (int k = i + 1; k < R - 1; k++) {
                    for (int l = j + 1; l < C - 1; l++) {
                        if (board[k][l] == (startW ? 'W' : 'B')) answer++;
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}