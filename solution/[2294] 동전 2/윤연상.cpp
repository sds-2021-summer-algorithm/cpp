/**********************************************************************
작성일 : 2021-08-26
작성자 : 윤연상
문제 :
	각 동전을 사용해서 k원을 만드는 데 사용되는 동전의 최소 개수
	ex) 1, 5 12원 동전으로 15원을 만드려면 최소 3개가 필요(5원 * 3)
풀이 :
	dp를 활용하기가 어려웠음
	dp[i][k] : i번째 동전까지 사용해서 k원을 만드는 데 사용한 동전 개수의 최소값
	점화식 : dp[i][k] = min(dp[i][k], dp[i][k-c[i]]+1)
		=> 점화식의 1차원은 고정되어있기 때문에
		dp[k] = min(dp[k], dp[k-c[i]]+1)을 사용
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n * k)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 100000

using namespace std;

int n, k;
int coin[101];
int dp[10010];

void _input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
}


int solve() {
	fill(dp + 1, dp + k + 1, INF);

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coin[i])
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}


	if (dp[k] == INF)
		return -1;
	else
		return dp[k];
}

int main(void) {
	fastio;

	_input();

	cout << solve();
}