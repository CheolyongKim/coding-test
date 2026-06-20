#include <string>
#include <vector>
#include <numeric>
using namespace std;
/*
    완탐스럽게 풀어도..?
    a + N * b = c + M * d
*/
int get_total_lcm(vector<vector<int>> signals){
    int ret = 1;
    for (auto signal : signals){
        int gyr = signal.at(0)+signal.at(1)+signal.at(2);
        ret = lcm(ret, gyr);
    }
    return ret;
}

bool is_answer(vector<int> status){
    for (int stat : status)
        if (stat != 1) return false;
    return true;
}

int solution(vector<vector<int>> signals) {
    int n = signals.size();
    vector<int> status; // Green(0), Yellow(1), Red(2)
    status.resize(n, 0);
    
    int time = 1;
    int total_lcm = get_total_lcm(signals);
    while (time-1 <= total_lcm){ 
        if (is_answer(status)) return time;
        else{
            time++;
            for (size_t i=0; i<n; i++){
                int t = time-1;
                auto signal = signals.at(i);
                int gyr = signal.at(0) + signal.at(1) + signal.at(2);
                
                t %= gyr;
                int color;
                if (t < signal.at(0)) color = 0;
                else if (t < signal.at(0)+signal.at(1)) color = 1;
                else color = 2;
                status.at(i) = color;
            }
        }
    }
    return -1;
}