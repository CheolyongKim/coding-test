#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    int n = elements.size();
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(elements.at(i));
    for (int i = 0; i < n; i++)
        v.push_back(elements.at(i));
    
    for (int i = 0; i < n; i++){
        for (int l = 1; l <= n; l++){
            int sum = 0;
            for (int j = 0; j < l; j++){
                sum += v.at(i + j);
            }
            s.insert(sum);
        }
    }
    return s.size();
}