#include <bits/stdc++.h>

using namespace std;

int n, m; // n : 행, m : 열
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int board[51][51];
int dp[51][51];					// dp[i][j] : 현재 (i,j)에서 최대로 이동할 수 있는 횟수 
int visited[51][51];

int dfs(int y, int x, int cnt);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// board 입력(구멍을 'H' 대신 -1로 표기)
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'H')
				board[i][j] = -1;
			else
				board[i][j] = s[j] - '0';
		}
	}

	int result = dfs(0, 0, 0);	// dfs 수행

	if (result == INT_MAX)
		cout << -1;
	else
		cout << result;
}

int dfs(int y, int x, int cnt) {
	if (y >= n || y < 0 || x >= m || x < 0) {	// 범위 초과시 리턴
		return cnt;
	}
	else if (board[y][x] == -1) {				// 도착지가 구멍일 때 리턴
		return cnt;
	}
	else if (visited[y][x] == 1) {				// 이미 다녀간 곳에 도착 시 => 사이클 => 무한대
		return INT_MAX;
	}
	else if (dp[y][x] != 0) {					// dp에 저장된 곳이면 굳이 더이상 dfs 수행 안하고 리턴
		return cnt + dp[y][x];
	}

	int retval = 0;
	int cur = board[y][x];

	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * cur;	// 다음 도착 좌표 계산
		int nx = x + dx[i] * cur;
		
		retval = max(retval, dfs(ny, nx, cnt + 1));
	}
	visited[y][x] = 0;
	dp[y][x] = retval-cnt;	// 현재 좌표에서의 dfs 수행 결과를 dp에 저장

	return retval;
}