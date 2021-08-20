/*
* 우선 그리디를 고려해보면 최적해를 구할 수 없음
*	=> ex) (3, 100) (100, 200), (200, 100), (100, 2)
* 
* 따라서 DP를 사용함
* => 구간 DP 문제 dp[i][j] : i번째 행렬부터 j번째 행렬까지 곱할 때의 연산 최소값
*/

#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

int n;
int dp[501][501];
pair<int, int> matrix[501];

void _input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		matrix[i] = make_pair(a, b);
	}
}

int getOpCnt(int i, int j, int k) {
	return matrix[i].first * matrix[k].second * matrix[j].second;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	_input();

	for (int term = 1; term < n; term++) {
		for (int i = 0; i + term < n; i++) {
			dp[i][i + term] = INF;

			for (int k = i; k <= i + term; k++) {
				dp[i][i + term] = min(dp[i][i + term], dp[i][k] + dp[k + 1][i + term] + getOpCnt(i, k, i + term));
			}

		}
	}
	cout << dp[0][n - 1];
}