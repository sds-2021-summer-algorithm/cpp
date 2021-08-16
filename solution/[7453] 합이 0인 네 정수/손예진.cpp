#include <iostream>
#include <vector>
#include <algorithm>

//type overflow 주의하기

using namespace std;

vector<long long> first, second;
vector<int> A, B, C, D;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			first.push_back(A[i] + B[j]);
			second.push_back(C[i] + D[j]);
		}
	}
	sort(first.begin(), first.end());
	sort(second.rbegin(), second.rend());
	int left = 0, right =  0;
	long long ans = 0;
	while (left < first.size() && right < second.size()) {
		long long sum = first[left] + second[right];
		if (sum == 0) {
			long long tmp1 = 1, tmp2 = 1;
			for (int i = left + 1; i < first.size(); i++, tmp1++) {
				if (first[left] != first[i])
					break;
			}
			for (int i = right + 1; i < second.size(); i++, tmp2++) {
				if (second[right] != second[i])
					break;
			}
			ans += tmp1 * tmp2;
			left += tmp1; right += tmp2;
		}
		else if (sum < 0)
			left++;
		else
			right++;
	}
	cout << ans << "\n";
}
