#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	comb(M, N)
	= M! / (M-N)! N!
*/

long long fac(long long x) {
	if (x <= 1ll) {
		return 1ll;
	}

	return x * fac(x - 1ll);
}

long long fac2(long long M, long long N) {
	long long ret = 1ll;
	for (long long i = 0; i < N; i++) {
		ret *= M - i;
	}
	return ret;
}

long long comb(long long M, long long N) {
	if (M - N < N) {
		return comb(M, M - N);
	}
	return fac2(M, N) / fac(N);
}

int main() {
	int T;
	long long N, M;
	cin >> T;
	vector<long long> answer;

	for (; T > 0; T--) {
		cin >> N >> M;
		answer.push_back(comb(M, N));
	}

	for (long long ans : answer) {
		cout << ans << endl;
	}

	return 0;
}