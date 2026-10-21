#include <string>
#include <vector>
#include <format>

using namespace std;

int stot(string s){
    return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
}

string ttos(int t){
    string ret = "";
    ret += format("{:0>2}", to_string(t/60));
    ret += ":";
    ret += format("{:0>2}", to_string(t%60));
    return ret;
}

int prev(int t){
    return t - 10 < 0 ? 0 : t - 10;
}

int next(int t, int len){
    return t + 10 > len ? len : t + 10;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    for (string command : commands){
        if (op_start <= pos && pos <= op_end) pos = op_end;
        
        if (command == "prev") pos = ttos(prev(stot(pos)));
        else if (command == "next") pos = ttos(next(stot(pos), stot(video_len)));
        
        if (op_start <= pos && pos <= op_end) pos = op_end;
    }
    return pos;
}