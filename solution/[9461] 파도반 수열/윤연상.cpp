/**********************************************************************
작성일 : 2021-08-26
작성자 : 윤연상
문제 :
	나선 모양으로 정삼각형이 이어져오는 규칙에서 각 정삼각형 변의 길이를 구함
풀이 :
	피보나치수열과 같은 단순 메모이제이션 문제
	점화식 : dp[n] = dp[n-1] + dp[n-5]
	n이 80정도 되면 dp[n]이 int 범위를 초과하기 때문에 long long을 사용해야함 (함정)
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n+m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

ll nums[101];

int main(void) {
	fastio;

	// 초기값 설정
	nums[0] = 1, nums[1] = 1, nums[2] = 1;
	nums[3] = 2, nums[4] = 2;

	for (int i = 5; i <= 100; i++) {
		nums[i] = nums[i - 1] + nums[i - 5];
	}

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n; cin >> n;
		cout << nums[n - 1] << '\n';
	}

	return 0;
}