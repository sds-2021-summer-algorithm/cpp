#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

static int n;
static int ans = 0;
static int board[15];		// board[1] = 3 : board[1][3]이 선택됨
static int visited[15];		// visited[3] = 1 : board[?][3]이 선택됨(3열)

// 두 퀸의 공격 가능 여부를 리턴
bool canAttack(int y2, int x2, int y1, int x1) {
	bool ret = false;
	if (y1 == y2 || x1 == x2)
		ret = true;
	else if (abs(y2 - y1) == abs(x2 - x1))
		ret = true;
	return ret;
}
// 현재 보드에 놓아진 퀸을 기준으로 새로운 퀸을 놓을 수 있는 지 여부
bool canPutQueen(int lev, int col) {
	bool ret = true;
	for (int i = 0; i < lev; i++) {
		if (canAttack(i, board[i], lev, col)) {
			ret = false;
		}
	}
	return ret;
}
// lev = 0 부터 lev = n-1까지 한개씩 퀸을 놓아보는 함수(dfs응용)
void dfs(int lev) {
	if (lev == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;
		if (canPutQueen(lev, i)) {
			visited[i] = 1;
			board[lev] = i;
			dfs(lev + 1);
			visited[i] = 0;
			board[lev] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	dfs(0);

	cout << ans;
}