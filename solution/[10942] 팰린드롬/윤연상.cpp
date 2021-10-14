/**********************************************************************
작성일 : 2021-10-14
작성자 : 윤연상
문제 :
	단순히 주어진 배열안에서 회문인지 아닌지 찾는 문제
	1 ≤ N(배열 크기) ≤ 2,000
	1 ≤ M(query) ≤ 1,000,000
풀이 :
	단순한 회문 검사는 O(n)이기 때문에 모든 쿼리를 검사하려면 O(n*m)이 소요된다.
	최악의 경우 20억번 연산해야하기 때문에 dp를 활용하여 연산 횟수를 줄여야함
	dp[i][j](배열 i~j번째 수가 회문인지 나타내는 이차원 배열)에 기록하면서 query를 수행
시간 제한 : 0.5초
메모리 제한 : 256MB
예상 시간복잡도 : ? 잘 모르겠음
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m;
int nums[2001];
bool dp[2001][2001];

int isPalindrome(int s, int e) {
	if (s >= e) return 1;
	else if (dp[s][e]) return 1;
	else if (nums[s] != nums[e]) return 0;

	int result = isPalindrome(s + 1, e - 1);
	if (result) dp[s][e] = true;
	return result;
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	
	cin >> m;
}

int main(void) {
	fastio;

	input();
	for (int i = 0; i < m; i++) {
		int s, e; cin >> s >> e;
		cout << isPalindrome(s, e) << '\n';
	}

	return 0;
}