#include <string>
#include <vector>

using namespace std;

bool is_good = true;

void check_person(vector<string> place, int i, int j){
    // 상하좌우
    int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
    for (int dir=0; dir<4; dir++){
        int y=i+dy[dir], x=j+dx[dir];
        if (y<0 || x<0 || y>=5 || x>=5) continue;
        
        if (place.at(y)[x] == 'P'){
            is_good = false;
            return;
        }
    }
    
    // 대각선
    for (int dir=0; dir<4; dir++){
        int y=i+dy[dir]+dy[(dir+1)%4], x=j+dx[dir]+dx[(dir+1)%4];
        if (y<0 || x<0 || y>=5 || x>=5) continue;
        
        if (place.at(y)[x] == 'P'){
            int y1=i+dy[dir], x1=j+dx[dir], y2=i+dy[(dir+1)%4], x2=j+dx[(dir+1)%4];
            if (place.at(y1)[x1]=='X' && place.at(y2)[x2]=='X'){
                continue;
            }
            else{
                is_good = false;
                return;
            }
        }
    }
    
    // 2칸
    for (int dir=0; dir<4; dir++){
        int y=i+dy[dir]*2, x=j+dx[dir]*2, y0=i+dy[dir], x0=j+dx[dir];
        if (y<0 || x<0 || y>=5 || x>=5) continue;
        
        if (place.at(y)[x] == 'P' && place.at(y0)[x0]!='X'){
            is_good = false;
            return;
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (vector<string> place : places){
        is_good = true;
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){
                if (place.at(i)[j] == 'P')
                    check_person(place, i, j);
            }
        }
        answer.push_back(is_good ? 1 : 0);
    }
    
    return answer;
}