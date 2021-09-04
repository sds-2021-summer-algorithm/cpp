/**********************************************************************
작성일 : 2021-09-03
작성자 : 윤연상
문제 :
	모든 토마토가 익은 토마토로 변하는 데 걸리는 시간을 구하는 문제
	2 <= m, n <= 1000
풀이 :
	기본 bfs 문제, 전형적인 삼성 ad 수준
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n*m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int m, n;
int cnt = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int tomato[1001][1001];

struct pos {
	int y, x;
	pos(int _y, int _x) : y(_y), x(_x) {};
};
deque<pos> ripes;	// 익은 과일


void breakpoint() {
	return;
}

void input() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			tomato[i][j] = a;

			if (a == 0)
				cnt++;
			else if (a == 1)
				ripes.push_back(pos(i, j));
		}
	}
}
int bfs() {
	int retval = 0;

	while (!ripes.empty()) {
		pos now = ripes.front();
		ripes.pop_front();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny >= n || ny < 0 || nx >= m || nx < 0)
				continue;
			if (tomato[ny][nx] != 0)
				continue;

			tomato[ny][nx] = tomato[now.y][now.x] + 1;
			cnt--;
			retval = max(retval, tomato[ny][nx]);
			ripes.push_back(pos(ny, nx));
		}
	}

	return retval - 1;
}

int main(void) {
	fastio;

	input();	// 입력값 받기
	
	if (cnt == 0) {	// 안 익은 토마토 없으면 바로 리턴
		cout << 0;
		return 0;
	}

	int result = bfs();

	if (cnt != 0)
		cout << -1;
	else
		cout << result;
}