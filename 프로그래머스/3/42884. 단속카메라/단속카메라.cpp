#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    ##
    -###
    
    ##
    --##
    
    ##
    ####
    
    ####
    -##-
*/

bool comp(vector<int> a, vector<int> b){
    if (a.at(1) == b.at(1)) return a.at(0) < b.at(0);
    else return a.at(1) < b.at(1);
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), comp);
    
    int met = 0;
    while (met < routes.size()){
        int right_pos = routes.at(met).at(1);
        while (met < routes.size() && routes.at(met).at(0) <= right_pos && right_pos <= routes.at(met).at(1)){
            met++;
        }
        answer++;
    }
    
    return answer;
}