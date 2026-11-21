#include <iostream>
#include <string>
#include <vector>

using namespace std;

int custom_pow(int a, int b) {
	if ((a % 10) <= 1 || (a % 10) == 6) {
		return a % 10;
	}

	int ret = 1;
	for (int i = 0; i < b; i++) {
		ret = (ret * a) % 10;
	}
	return ret;
}

int main() {
	int T;
	int a, b;
	vector<int> answer;

	cin >> T;
	for (; T > 0; T--) {
		cin >> a >> b;
		int p = custom_pow(a, b);
		answer.push_back(p == 0 ? 10 : p);
	}

	for (int i : answer) {
		cout << i << endl;
	}

	return 0;
}