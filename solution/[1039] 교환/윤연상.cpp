#include <bits/stdc++.h>

using namespace std;

int m, k;
int n[7];
int dp[11][1000001];	// 중복을 스킵하기 위한 메모 배열
						// ex) dp[3][num] : 3번 바꾼 후 num값일 때 나머지 연산 수행 후의 최대값


void swap(int i, int j) {	// i번째 자리 수와 j번째 자리 수를 교환
	int tmp = n[i];
	n[i] = n[j];
	n[j] = tmp;
}
int get_fullnumber() {		// n배열을 정수로 반환
	int retval = 0;
	for (int i = 0; i < m; i++) {
		retval = retval * 10 + n[i];
	}
	return retval;
}
int dfs(int cnt) {			// dfs 수행
	if (cnt == k) {
		return get_fullnumber();
	}
	else if (dp[cnt][get_fullnumber()] != 0) {
		return dp[cnt][get_fullnumber()];
	}

	int ret = 0;

	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			if (n[j] == 0 && i == 0) {
				continue;
			}
			swap(i, j);
			int result = dfs(cnt + 1);
			dp[cnt+1][get_fullnumber()] = result;	// dfs 결과를 dp에 저장
			ret = max(ret, result);
			swap(i, j);
		}
	}
	
	return ret;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 초기 조건 입력
	string s; 
	cin >> s >> k;
	m = s.size();
	for (int i = 0; i < m; i++) {
		n[i] = s[i] - '0';
	}

	// n이 두자리수이면서 10의 배수인 경우와 n이 한자리수인 경우 -1
	if ((m == 2 && n[1] == 0) || m == 1) {
		cout << -1;
	}
	else {
		cout << dfs(0);
	}
}