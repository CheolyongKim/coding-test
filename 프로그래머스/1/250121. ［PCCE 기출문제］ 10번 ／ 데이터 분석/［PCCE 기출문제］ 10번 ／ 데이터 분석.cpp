#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define C "code"
#define D "date"
#define M "maximum"
#define R "remain"

bool comp(auto a, auto b, int o){
    return a.at(o) < b.at(o);
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    map<string, int> convert = {{C,0}, {D,1}, {M,2}, {R,3}};
    
    for (auto d : data){
        if (d.at(convert[ext]) < val_ext) answer.push_back(d);
    }
    
    int o = convert[sort_by];

    sort(answer.begin(), answer.end(),
        [o](const vector<int>& a, const vector<int>& b) {
            return comp(a, b, o);
        }
    );
    
    return answer;
}