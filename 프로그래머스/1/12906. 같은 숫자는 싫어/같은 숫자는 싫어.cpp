#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    for (int a:arr){
        if (st.empty() || st.top()!=a){
            answer.push_back(a);
            st.push(a);
        }
    }
    return answer;
}