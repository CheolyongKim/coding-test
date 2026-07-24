#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> tbc; // 차량번호, 입차시간(출차할때 초기화)
    map<string, int> ttt; // 차량번호, 총 시간
    map<string, int> fbc; // 차량번호, 총 요금
    
    int basef = fees.at(1), baset = fees.at(0), mulf = fees.at(3);
    double divt = fees.at(2);
    
    for (string r : records){
        string hour = r.substr(0, 2);
        if (hour[0]=='0') hour = hour.substr(1,1);
        string min = r.substr(3, 2);
        if (min[0]=='0') min = min.substr(1,1);
        string car = r.substr(6, 4);
        string flag = r.substr(11, 2);
        
        int time = stoi(hour)*60 + stoi(min);
        
        if (tbc.contains(car)){
            if (flag == "IN"){
                cout << "입차 두번??\n";
                break;
            }else{
                //int fee = basef + ceil((time - tbc[car] - baset < 0 ? 0 : time - tbc[car] - baset)/divt) * mulf;
                int tt = time - tbc[car];
                if (ttt.contains(car)) ttt[car] += tt;
                else ttt[car] = tt;
                tbc.erase(car);
            }
        }else{
            if (flag == "IN"){
                tbc[car] = time;
            }else{
                cout << "없는데 출차??\n";
                break;
            }
        }
    }
    
    for (auto t : tbc){
        ///int fee = basef + ceil((24*60-1 - t.second - baset < 0 ? 0 : 24*60-1 - t.second - baset)/divt) * mulf;
        int time = 24*60-1 - t.second;
        if (ttt.contains(t.first)) ttt[t.first] += time;
        else ttt[t.first] = time;
    }
    
    for (auto t : ttt){
        int fee = basef + ceil((t.second - baset < 0 ? 0 : t.second - baset)/divt) * mulf;
        fbc[t.first] = fee;
    }
    
    vector<int> answer;
    for (auto f : fbc) answer.push_back(f.second);
    return answer;
}