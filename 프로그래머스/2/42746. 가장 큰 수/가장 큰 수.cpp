#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    string ab = a+b, ba = b+a;
    return ab>ba ? true:false;
}

bool only_contains_zero(string s){
    bool ret = true;
    for (char c : s){
        if (c!='0') ret = false;
    }
    return ret;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    size_t n = numbers.size();
    vector<string> ns(n);
    for (size_t i=0; i<n; i++){
        ns.at(i) = to_string(numbers.at(i));
    }
    
    sort(ns.begin(), ns.end(), compare);
    
    for (string s : ns){
        answer += s;
    }
    
    if (only_contains_zero(answer)){
        return "0";
    }
    
    return answer;
}