/**********************************************************************
작성일 : 2021-08-24
작성자 : 윤연상
문제 :
	시간 제한 : 0.5초
	가치가 다른 동전을 사용하여 가격 k를 만들 수 있는 경우의 수를 구함
	ex) 1, 3, 5 인 가격을 가지는 동전으로 10원을 만드는 경우의 수
	총 10가지 방법으로 10원을 만들 수 있음 (중복되는 경우는 제외 2 2 2 2 2 5 == 2 2 2 5 2 2)
풀이 :
	난이도가 쉬운 문제이긴 하지만 제약조건이 까다롭고 공간복잡도, 시간복잡도 모두 고려해야함
	점화식 : dp[i, k]는 i번째 동전까지만 사용해서 k원을 만드는 경우의 수, C(i)는 i번째 동전 가격
		=> dp[i, k] = dp[i-1, k]	(if C(i) > k)
					= dp[i-1, k] + dp[i, k-C(i)]	(if C(i) <= k)
	이를 구현하기 위해 dp를 2차원 배열로 구현시 int [100][10000] : 4MB 정도 (메모리 초과)
	따라서 일차원 배열로 구현해야함
		=> dp[k] = dp[k] or dp[k] + dp[k-C(i)]
시간 제한 : 0.5초
메모리 제한 : 4MB
예상 시간복잡도 : O(n*k) (10^6 정도)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, k;
int coin[101];
int dp[10002];

int solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (coin[i] <= j) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}
	return dp[k];
}

int main(void) {
	fastio;

	cout << solve();
}