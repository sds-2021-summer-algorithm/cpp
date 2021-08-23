/*
* 아래칸과 위칸 중 최적값만 선택하는 그리디로는 해결 불가능
* 
* 메모이제이션을 사용 (bottom up 방식으로 메모)
* dp[0][i] : i번째 줄까지 i번째 윗칸을 선택하는 최대값
* dp[1][i] : i번째 줄까지 i번째 아래칸을 선택하는 최대값
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int tc;
int n;
int num[2][100001];
int dp[2][100001];

int solve() {
	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num[i][j];
		}
	}

	dp[0][0] = num[0][0]; dp[1][0] = num[1][0];
	dp[0][1] = num[1][0] + num[0][1];
	dp[1][1] = num[0][0] + num[1][1];

	for (int i = 0; i < n - 2; i++) {
		dp[0][i + 2] = max(dp[1][i + 1] + num[0][i + 2], max(dp[0][i] + num[0][i + 2], dp[1][i] + num[0][i + 2]));
		dp[1][i + 2] = max(dp[0][i + 1] + num[1][i + 2], max(dp[0][i] + num[1][i + 2], dp[1][i] + num[1][i + 2]));
	}

	return max(dp[0][n - 1], dp[1][n - 1]);
}

int main(void) {
	fastio;

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cout << solve() << '\n';
	}
}
