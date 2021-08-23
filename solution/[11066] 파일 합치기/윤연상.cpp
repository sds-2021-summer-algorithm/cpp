/**********************************************************************
작성일 : 2021-08-23
작성자 : 윤연상
문제 :
	여러 개의 파일 합치는 비용을 최소화 하는 문제
	40 30 30 50 => 70 30 50 => 70 80 => 150 
	이 순서로 파일을 합칠 때 70 + 80 + 150 = 300의 비용 발생
	이러한 비용이 최소인 최적해를 구해야함
풀이 :
	그리디로는 최적해를 구할 수 없다.
	=> dp를 통한 메모이제이션과 구간을 정의하는 2차원 dp를 사용 
	dp[i][j]는 i부터 j까지의 파일들을 합치는 최소 비용
	점화식 => dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[i][j])
예상 시간복잡도 : O(n^3) (n의 범위가 500이하이기 때문에 가능)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 200000000

using namespace std;

int tc;
int n;
int files[501], sum[501];
int dp[501][501];

void init_dp() {	// dp배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = INF;
		}
	}
}
void init_sum() {	// 누적합 배열 생성
	sum[0] = files[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + files[i];
	}
}

int solve() {
	// 초기값 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> files[i];
	}

	init_sum();	// 누적합 생성
	init_dp();	// dp 초기화

	// 메모이제이션 시작
	for (int term = 0; term < n; term++) {
		for (int row = 0; row + term < n; row++) {
			int left = row; int right = row + term;
			for (int mid = left; mid <= right; mid++) {
				dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid + 1][right] + sum[right] - sum[left - 1]);
				
			}
		}
	}

	return dp[0][n - 1];
}

int main(void) {
	fastio;

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cout << solve() << '\n';
	}
}