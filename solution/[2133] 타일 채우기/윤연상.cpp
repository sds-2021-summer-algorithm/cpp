/**********************************************************************
작성일 : 2021-08-27
작성자 : 윤연상
문제 :
	2칸짜리 타일로 높이가 3인 벽을 만들 수 있는 경우의 수를 구하라
풀이 :
	메모이제이션을 통한 dp로 해결
	높이가 3이기 때문에 홀수 길이는 만들지 못함
	점화식 : dp[i] = dp[i-2] * 3 + ∑dp[i - 2n]*2
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^2)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[31];

int main(void) {
	fastio;

	dp[0] = 1;

	for (int i = 2; i <= 30; i++) {
		dp[i] += dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}

	int n; cin >> n;
	cout << dp[n];
}