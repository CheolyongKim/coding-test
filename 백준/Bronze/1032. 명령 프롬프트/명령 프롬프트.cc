#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	all same, or not
*/

bool all_same(vector<string> f, int index) {
	char pivot = f.at(0)[index];

	for (string s : f) {
		if (s[index] != pivot) {
			return false;
		}
	}
	return true;
}

int main() {
	int N;
	string answer = "";

	cin >> N;
	vector<string> filenames(N);

	for (int i = 0; i < N; i++) {
		cin >> filenames.at(i);
	}

	for (int i = 0; i < filenames.at(0).length(); i++) {
		if (all_same(filenames, i)) {
			answer += filenames.at(0)[i];
		}
		else {
			answer += "?";
		}
	}

	cout << answer;

	return 0;
}