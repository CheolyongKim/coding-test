#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();
    answer.resize(n);
    stack<int> st;
    
    for (int i = n-1; i>=0; i--){
        if (st.empty()){
            answer.at(i) = -1;
            st.push(numbers.at(i));
        }
        else{
            while (!st.empty() && st.top() <= numbers.at(i)) st.pop();
            if (st.empty()) answer.at(i) = -1;
            else answer.at(i) = st.top();
            st.push(numbers.at(i));
        }
    }
    
    return answer;
}