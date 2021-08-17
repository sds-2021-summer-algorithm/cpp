/*
* dfs를 통한 완전탐색과 투 포인터를 응용
* 아이디어 사고과정 :
* N이 최대 40이므로 완전탐색 수행시 2^40(천억)번 연산 => 1초 훨씬 넘음
* 배열을 두개로 쪼갠다음 각각의 부분수열을 계산(2^20번은 100만 정도)
* 부분수열의 합 배열 두개를 투포인터를 이용하여 전체 부분수열의 합을 구함
* 
* 함정 : int 범위를 초과하는 문제이기 때문에 long long을 사용해야했음.... 이거 때문에 고생함
* 시간 : 208ms
* 메모리 : 26MB
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, s, half;
ll ans = 0;
vector<ll> num1, num2, sum1, sum2;

bool cmp(ll& a, ll& b) { return a > b; }

void _input() {
	// 입력 함수
	cin >> n >> s;
	half = n / 2;

	for (int i = 0; i < half; i++) {
		ll a; cin >> a;
		num1.push_back(a);
	}
	for (int i = 0; i < n - half; i++) {
		ll a; cin >> a;
		num2.push_back(a);
	}
}

void dfs1(int idx, ll sum, bool isVisit) {
	// 첫 번째 배열 dfs
	if (idx == half) {
		if (isVisit) {
			sum1.push_back(sum);
			if (sum == s) ans++;
		}
		return;
	}
	dfs1(idx + 1, sum, isVisit);
	dfs1(idx + 1, sum + num1[idx], true);
}
void dfs2(int idx, ll sum, bool isVisit) {
	// 두 번째 배열 dfs
	if (idx == n - half) {
		if (isVisit) {
			sum2.push_back(sum);
			if (sum == s) ans++;
		}
		return;
	}
	dfs2(idx + 1, sum, isVisit);
	dfs2(idx + 1, sum + num2[idx], true);
}
void two_pointer() {
	// 투 포인터 알고리즘
	int p1 = 0; int p2 = 0;
	
	while (p1 < sum1.size() && p2 < sum2.size()) {
		ll cur = sum1[p1] + sum2[p2];

		if (cur == s) {
			int cnt1 = 1; int cnt2 = 1;
			for (int i = p1 + 1; i < sum1.size(); i++) {
				if (sum1[i] == sum1[p1])
					cnt1++;
				else
					break;
			}
			for (int i = p2 + 1; i < sum2.size(); i++) {
				if (sum2[i] == sum2[p2])
					cnt2++;
				else
					break;
			}
			ans += (ll)cnt1 * cnt2;
			p1 += cnt1; p2 += cnt2;
		}
		else if (cur < s) {
			p1++;
		}
		else if (cur > s) {
			p2++;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	_input();

	dfs1(0, 0, false);
	dfs2(0, 0, false);

	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end(), cmp);

	two_pointer();

	cout << ans;
}