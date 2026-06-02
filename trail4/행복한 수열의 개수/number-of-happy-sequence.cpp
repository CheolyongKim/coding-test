#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int answer=0;

    for (int i=0; i<n; i++){
        int maxStreakR=1, curStreakR=1, maxStreakC=1, curStreakC=1;
        for (int j=1; j<n; j++){
            if (grid[i][j]==grid[i][j-1])  curStreakR++;
            else{
                if (curStreakR > maxStreakR) maxStreakR = curStreakR;
                curStreakR = 1;
            }
            if (grid[j][i]==grid[j-1][i]) curStreakC++;
            else{
                if (curStreakC > maxStreakC) maxStreakC = curStreakC;
                curStreakC = 1;
            }
        }
        if (maxStreakR >= m || curStreakR >= m) answer++;
        if (maxStreakC >= m || curStreakC >= m) answer++;
    }

    cout << answer;

    return 0;
}
