#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long N;
	long long answer = 0;
	cin >> N;

	long long num = 10;
	long long cnt = 1;
	while (num <= N) {
		long long temp = num - (num / 10);
		answer += (cnt * temp);
		cnt++;
		num *= 10;
	}

	long long start = num / 10;
	long long temp = N - start + 1;

	answer += (cnt * temp);

	cout << answer << "\n";
	return 0;

}