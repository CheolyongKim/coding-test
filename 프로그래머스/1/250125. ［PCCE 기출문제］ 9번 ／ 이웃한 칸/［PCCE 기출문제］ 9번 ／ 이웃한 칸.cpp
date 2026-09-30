#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    int dy[4] = {-1,1,0,0}, dx[4] = {0,0,-1,1};
    for (int i=0; i<4; i++){
        int y = h + dy[i], x = w + dx[i];
        if (y<0 || x<0 || y>=n || x>=n) continue;
        if (board.at(h).at(w) == board.at(y).at(x)) answer++;
    }
    return answer;
}