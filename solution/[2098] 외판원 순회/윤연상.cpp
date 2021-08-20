/*
* 유명한 외판원 순회 문제
* 완전탐색 사용시 n!번 연산(n이 17 넘어갈 시 수가 매우 커짐)
* 
* 따라서 dp를 활용하여 중복 계산을 방지
* dp[city][visit] : city는 현재 위치하고 있는 도시, visit는 방문했던 도시
*	=> visit는 비트마스킹을 통한 2진수 => 10진수 표현 (21 : 10101 => 1, 3, 5번 도시 방문)
* 
*/
#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

int n, full_visit;
int weight[17][17];
int dp[17][65536];

void _input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> weight[i][j];
		}
	}
	full_visit = (1 << n) - 1;
	fill(&dp[0][0], &dp[16][65535], INF);
}

int dfs(int bits, int cur_city) {
	if (dp[cur_city][bits] != INF) {	// 이미 계산되어있으면 바로 리턴
		return dp[cur_city][bits];
	}
	else if (bits == full_visit) {		// 모든 도시를 방문
		if (weight[cur_city][0] == 0)	// 출발지로 이동 못하면 INF
			return INF;
		else
			return weight[cur_city][0];	// 출발지로 가는 거리 리턴
	}

	for (int i = 0; i < n; i++) {
		if (weight[cur_city][i] == 0)
			continue;
		if ((bits & (1 << i)) == (1 << i))	// i번째 도시에 방문했는지 검사
			continue;

		// 백트레킹으로 최소거리를 dp에 기록 (현재 값과 dfs 호출 값을 비교)
		dp[cur_city][bits] = min(dp[cur_city][bits], weight[cur_city][i] + dfs(bits + (1 << i), i));
	}
	return dp[cur_city][bits];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	_input();

	cout << dfs(1, 0);
}