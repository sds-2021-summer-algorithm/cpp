/*
* dfs를 통한 완전탐색 문제
* 판단 근거	: 정수의 개수는 20개 => 완전탐색 수행시 2^20(대략 100만)번 연산
*			: 1초는 대략 1억번 연산까지는 가능함
*/
#include <bits/stdc++.h>

using namespace std;

int n, s;
int ans = 0;
int nums[21];

void dfs(int idx, int sum) {
	if (idx == n) {
		if (sum == s) ans++;
		return;
	}

	dfs(idx + 1, sum);
	dfs(idx + 1, sum + nums[idx]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	dfs(0, 0);
	if (s == 0)
		cout << ans - 1;
	else
		cout << ans;
}