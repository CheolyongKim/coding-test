#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

vector<string> split(string target, string del){
    vector<string> ret;
    int prev = 0, cur = target.find(del);
    if (cur == target.npos){
        ret.push_back(target);
        return ret;
    }
    while (cur != target.npos && cur < target.length()){
        ret.push_back(target.substr(prev, cur - prev));
        prev = cur + del.length();
        cur = target.find(del, prev);
    }
    ret.push_back(target.substr(prev, target.length() - prev));
    return ret;
}

bool comp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    // trim string into vector
    s = s.substr(2, s.length()-4);
    vector<string> vs = split(s, "},{");
    int n = vs.size();
    vector<vector<string>> vvs(n);
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++){
        vvs.at(i) = split(vs.at(i), ",");
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < vvs.at(i).size(); j++){
            v.at(i).push_back(stoi(vvs.at(i).at(j)));
            //cout << vvs.at(i).at(j) << " ";
        }
        //cout << "\n";
    }
    
    sort(v.begin(), v.end(), comp);
    
    set<int> ss;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < v.at(i).size(); j++){
            if (!ss.contains(v.at(i).at(j))){
                ss.insert(v.at(i).at(j));
                answer.push_back(v.at(i).at(j));
            }
        }
    }
    
    return answer;
}