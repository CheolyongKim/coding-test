#include <vector>
#include <iostream>
using namespace std;
int MOD = 20170805;

/*
    0 2 0 0 0 2
    0 0 2 0 1 0
    1 0 0 2 2 0
*/

void debug(vector<vector<int>> v){
    for (auto i : v){
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<int>> l(m), u(m);
    for (int i = 0; i < m; i++) {
        l.at(i).resize(n, 0);
        u.at(i).resize(n, 0);
    }
    
    l.at(0).at(1) = 1;
    u.at(1).at(0) = 1;
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            // 위에서 내려오는 경우
            if (i > 0 && city_map.at(i-1).at(j) != 1){
                if (city_map.at(i-1).at(j) == 2) u.at(i).at(j) += u.at(i-1).at(j);
                else u.at(i).at(j) += l.at(i-1).at(j) + u.at(i-1).at(j);
            }
            
            // 왼쪽에서 오는 경우
            if (j > 0 && city_map.at(i).at(j-1) != 1){
                if (city_map.at(i).at(j-1) == 2) l.at(i).at(j) += l.at(i).at(j-1);
                else l.at(i).at(j) += l.at(i).at(j-1) + u.at(i).at(j-1);
            }
            
            l.at(i).at(j) %= MOD;
            u.at(i).at(j) %= MOD;
        }
    }
    
    if (m == 3 && n == 6){
        debug(l);
        debug(u);
    }
    
    return (l.at(m-1).at(n-1)%MOD + u.at(m-1).at(n-1)%MOD) % MOD;
}