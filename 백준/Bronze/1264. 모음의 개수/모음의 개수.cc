#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> answer;
	string line = "";

	while (true) {
		int count = 0;
		getline(cin, line);
		if (line == "#") {
			break;
		}

		for (char c : line) {
			char l = tolower(c);
			if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') {
				count++;
			}
		}
		answer.push_back(count);
	}

	for (int i : answer) {
		cout << i << endl;
	}

	return 0;
}