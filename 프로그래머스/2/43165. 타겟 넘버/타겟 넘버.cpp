#include <string>
#include <vector>

using namespace std;

int cal(vector<int> numbers, int idx, int cur, int target) {
    if (idx == numbers.size()-1) {
        return (cur + numbers[idx] == target || cur - numbers[idx] == target) ? 1 : 0;
    }
    return cal(numbers, idx+1, cur + numbers[idx], target) + cal(numbers, idx+1, cur - numbers[idx], target);
}

int solution(vector<int> numbers, int target) {
    /*
    재귀적으로?
    numbers[1:] ... 반복
    */
    return cal(numbers, 0, 0, target);
}