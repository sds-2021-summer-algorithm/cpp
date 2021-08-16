#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* <idea> 
* 40개의 원소에 대한 부분 수열을 구하면 총 2^40개임. -> 시간 초과 & 메모리 초과
* 따라서 부분 수열의 합을 두 집합으로 쪼개서 투 포인터로 S 구하기. (각 N / 2개씩)
* -> 한 집합 내에서 구할 수 있는 경우, 두 집합간의 합으로 구할 수 있는 경우로 나눠서 답 구하기
* <주의할 점>
* 1. type overflow - 부분 수열의 개수는 최대 2^40개
* 2. 부분 수열의 크기는 양수가 돼야하기 때문에 공집합의 경우 각 부분 수열에 추가하면 안 됨.
*/

int N, S;
long long cnt;
vector<int> l, r, nums;

void GetSubSum(int s, int e, int sum, int idx, bool left, bool all0) {	//부분 수열의 합 구하기
	if (idx > e) {
		if (all0)
			return;
		if (sum == S)	//한 집합 안에서 S를 구할 수 있는 경우
			cnt++;
		if (left)
			l.push_back(sum);
		else
			r.push_back(sum);
		return;
	}
	GetSubSum(s, e, sum, idx + 1, left, all0);
	GetSubSum(s, e, sum + nums[idx], idx + 1, left, false);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		nums.push_back(n);
	}
	sort(nums.begin(), nums.end());
	GetSubSum(0, N / 2, 0, 0, 1, 1);
	GetSubSum(N / 2 + 1, N - 1, 0, N / 2 + 1, 0, 1);
	sort(l.begin(), l.end());
	sort(r.rbegin(), r.rend());
	
	int left = 0, right = 0;
	while (left < l.size() && right < r.size()) {
		int sum = l[left] + r[right];
		if (sum == S) {	//두 집합 간의 합을 통해 S를 구할 수 있는 경우
			long long tmp1 = 1, tmp2 = 1;
			for (int i = left + 1; i < l.size(); i++, tmp1++) {
				if (l[left] != l[i])
					break;
			}
			for (int i = right + 1; i < r.size(); i++, tmp2++) {
				if (r[right] != r[i])
					break;
			}
			left += tmp1; right += tmp2;
			cnt += tmp1 * tmp2;
		}
		else if (sum < S) {
			left++;
		}
		else if (sum > S) {
			right++;
		}
	}
	cout << cnt << "\n";
}
