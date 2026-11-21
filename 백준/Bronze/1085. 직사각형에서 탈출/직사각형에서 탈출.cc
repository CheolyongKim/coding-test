#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	vector<int> dist = { x, y, w - x, h - y };

	cout << *min_element(dist.begin(), dist.end());

	return 0;
}