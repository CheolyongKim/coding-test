#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    mats.size() <= 10
    mats 자체 크기 <= 400
    park.size()^2 <= 2500
    brute force 가능
*/

int solution(vector<int> mats, vector<vector<string>> park) {
    int jimin_has = mats.size();
    int n = park.size(), m = park.at(0).size();
    
    // 돗자리 큰 것부터 탐색
    sort(mats.begin(), mats.end());
    
    for (; jimin_has > 0; jimin_has--){
        int mat_size = mats.at(jimin_has - 1);
        
        // 공원 내에 자리가 있는지
        for (int pi = 0; pi < n; pi++){
            for (int pj = 0; pj < m; pj++){
                bool possible = true;
                for (int fi = 0; possible && fi < mat_size; fi++){
                    for (int fj = 0; possible && fj < mat_size; fj++){
                        int i = pi + fi, j = pj + fj;
                        if (i<0 || j<0 || i>=n || j>=m){
                            possible = false;
                            continue;
                        }
                        string cell = park.at(i).at(j);
                        if (cell != "-1") possible = false;
                    }
                }
                if (possible) return mat_size;
            }
        }
    }
    return -1;
}