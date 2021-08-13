/*
* 단순한 스도쿠 채우기 문제
* dfs를 통한 완전 탐색 + 조건을 만족하는 케이스 하나만 찾고 바로 종료
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

static int board[9][9];

struct pos {
	int y, x;
	pos(int _y, int _x) :y(_y), x(_x) {};
};
deque<pos> blank;

// p 위치에 num을 넣을 수 있는 지 체크
bool check(pos p, int num) {
	for (int i = 0; i < 9; i++) {
		// 가로
		if (board[p.y][i] == num)
			return false;
		// 세로
		if (board[i][p.x] == num)
			return false;
	}
	// 3x3 구역 
	int sy = p.y - p.y % 3;
	int sx = p.x - p.x % 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[sy + i][sx + j] == num)
				return false;
		}
	}
	return true;
}
// 빈칸에 한개씩 숫자를 넣어보면서 dfs 수행
// 빈칸을 모두 채웠을 때 true를 리턴하여 모든 함수 종료
bool dfs() {
	if (blank.empty()) {
		return true;
	}
	pos now = blank.front(); blank.pop_front();

	for (int i = 1; i <= 9; i++) {
		if (check(now, i)) {
			board[now.y][now.x] = i;
			if (dfs())
				return true;
			board[now.y][now.x] = 0;
		}
	}
	blank.push_front(now);
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				blank.push_back(pos(i, j));
			}
		}
	}

	dfs();

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}