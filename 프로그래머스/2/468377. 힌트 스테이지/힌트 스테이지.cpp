#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
/*
    일단 문제 이해부터가 어려움..
    cost: 스테이지 해결 비용(힌트권 사용 수에 따른)
    hint: 힌트권의 판매 가격과 힌트권 번호 번들(스테이지에 따른)
    |
    (처리): 관건은 
    힌트권을 사느냐 마느냐(왜냐하면 안사면 암튼 정해진 비용뿐이니까)
    인데 사는 비용 vs 삼으로써 줄어드는 비용을 비교하면 됨
    -> 처음에 hint 싹 돌면서 ... 아 근데 1장쓰면 미미하게 감소인데 2장쓰면 크게 감소 -> 이런경우는 어떻게?
    -> 처음에 hint 싹 돌면서 stage_num번 힌트권을 q개까지 살 수 있고, <가격, 사는 개수> 형태로 저장해놓음 (사는 개수가 연속적이지 않으므로)
    / 아님 차라리 스테이지마다 산다 vs 안산다니까 2^(n-1)..?
    -> 2^15 = 1024*32 괜찮을수도?
    |
    모든 스테이지를 해결하는데 필요한 최소 비용
*/

// def
#define MIN(a, b) a<b ? a:b
vector<vector<int>> global_cost, global_hint;
size_t n;
priority_queue<int> pq;

void calculate_cost(size_t cur_stage, int hint_bought){
    // hint_bought: 비트 낮은자리부터 샀으면 1, 안샀으면 0
    // ex) 101: 스테이지 1, 3에서 샀다
    if (cur_stage == n-1){
        // calculate final cost
        int final_cost = 0;
        
        vector<int> hint_usage(n, 0);
        for (size_t past_stage = 0; past_stage < n-1; past_stage++){
            if ((hint_bought >> past_stage) & 1){
                final_cost += global_hint.at(past_stage).at(0);
                for (size_t each_hint=1; each_hint < global_hint.at(past_stage).size(); each_hint++){
                    hint_usage.at(global_hint.at(past_stage).at(each_hint) - 1)++;
                }
            }
        }
        
        for (size_t stage_calc_idx = 0; stage_calc_idx < n; stage_calc_idx++){
            final_cost += global_cost.at(stage_calc_idx).at(MIN(n-1, hint_usage.at(stage_calc_idx)));
        }
        
        pq.push(-final_cost); // MIN pq
    }
    else{
        calculate_cost(cur_stage + 1, hint_bought); // 0
        calculate_cost(cur_stage + 1, pow(2, cur_stage) + hint_bought); // 1
    }
    /*
        1 1
        2 11
        3 111
        4 1111 -> 
    */
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    global_cost = cost;
    global_hint = hint;
    n = cost.size();
    
    calculate_cost(1, 0);
    calculate_cost(1, 1);
    
    return -pq.top(); // MIN pq
}