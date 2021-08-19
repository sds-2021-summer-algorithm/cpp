/*
* 그리디로 풀려고 시도했음 (매 입력마다 최적 이동을 함)
*	=> 결국은 그리디로는 최적해를 구할 수 없었음 (반례를 찾아야하는 데 못찾음...)
* 
* 반례 : 첫 두개의 이동을 한발로만 했을 때
*	=> dp를 이용함 => dp의 차원 결정은 (입력 횟수, 왼쪽 발, 오른쪽 발) => 3차원
* dp[n][i][j] : n번째 입력 수행시 발이 (i, j)에 있을 때의 최소 이동
* 점화식(목표 지점 : target) 
*	=> dp[n][i][target] = dp[n][i][target] 과 dp[n-1][i][j] + 이동 중 작은 값
*	=> dp[n][target][j] = dp[n][target][j] 과 dp[n-1][i][j] + 이동 중 작은 값
*/

#include <bits/stdc++.h>
#define	INF 200000000

using namespace std;

int dp[100001][5][5];

void init() {
	fill(&dp[0][0][0], &dp[100000][4][4], INF);
	dp[0][0][0] = 0;
}

int get_movement(int cur, int nex) {
	if (cur == nex) return 1;
	else if (cur == 0) return 2;
	else if (abs(cur - nex) != 2) return 3;
	else return 4;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	init();

	int n = 0;
	while (1) {
		int target; cin >> target;

		if (target == 0) break;
		else n++;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (dp[n - 1][i][j] == INF)
					continue;
				if (i == j && n > 1)
					continue;
				
				if (i != target)
					dp[n][i][target] = min(dp[n][i][target], dp[n - 1][i][j] + get_movement(j, target));
				if (j != target)
					dp[n][target][j] = min(dp[n][target][j], dp[n - 1][i][j] + get_movement(i, target));
			}
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j) continue;
			ans = min(ans, dp[n][i][j]);
		}
	}
	cout << ans;
}