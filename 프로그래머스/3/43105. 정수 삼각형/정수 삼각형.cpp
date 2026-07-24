#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    vector<int> ans(n, 0);
    // in left, in right
    vector<vector<int>> il(n), ir(n);
    
    for (int i = 0; i < n; i++){
        int m = triangle.at(i).size();
        il.at(i).resize(m, 0);
        ir.at(i).resize(m, 0);
    }
    
    for (int i = 0; i < n-1; i++){
        int m = triangle.at(i).size();
        for (int j = 0; j < m; j++){
            int k = triangle.at(i).at(j) + max(il.at(i).at(j), ir.at(i).at(j));
            ir.at(i+1).at(j) = k;
            il.at(i+1).at(j+1) = k;
        }
    }
    
    for (int i = 0; i < n; i++){
        ans.at(i) = triangle.at(n-1).at(i) + max(il.at(n-1).at(i), ir.at(n-1).at(i));
    }
    
    return *max_element(ans.begin(), ans.end());
}