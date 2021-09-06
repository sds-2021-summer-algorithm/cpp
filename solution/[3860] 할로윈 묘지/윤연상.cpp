#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int w, h, g, e;
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

struct pos {
	int x, y;
	pos(int _x, int _y) : x(_x), y(_y) {};
};
struct edge {
	pos start, end;
	int cost;
	edge(int x1, int y1, int x2, int y2, int c) : 
		start(x1, y1), end(x2, y2), cost(c) {};
};
vector<edge> edgelist;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		int ishole[31][31];	// 구멍 기록
		int map[31][31];	// 묘비 기록
		int dp[31][31];		// dist 기록
		
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				map[i][j] = 0;
				ishole[i][j] = 0;
				dp[i][j] = INF;
			}
		}

		cin >> w >> h;
		if (w == 0) break;

		// 묘비 리스트 초기화
		cin >> g;
		for (int i = 0; i < g; i++) {
			int a, b;
			cin >> a >> b;
			map[b][a] = 1;
		}
		
		// 간선리스트에 귀신 구멍 추가
		cin >> e;
		for (int i = 0; i < e; i++) {
			int x1, y1, x2, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			ishole[y1][x1] = 1;
			edgelist.push_back(edge(x1, y1, x2, y2, t));
		}

		// 간선리스트 초기화
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if ((i == h - 1 && j == w - 1) || map[i][j] == 1 || ishole[i][j] == 1) 
					continue;
				for (int k = 0; k < 4; k++) {
					int ni = i + di[k];
					int nj = j + dj[k];
					if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
						if (map[ni][nj] != 1)
							edgelist.push_back(edge(j, i, nj, ni, 1));
					}
				}
			}
		}

		// 벨만 포드 시작
		bool flag = false;
		dp[0][0] = 0;
		for (int i = 1; i <= w * h - g; i++) {
			for (edge &now : edgelist) {
				int sx = now.start.x; int sy = now.start.y;
				int ex = now.end.x; int ey = now.end.y;
				if (dp[sy][sx] != INF && dp[ey][ex] > dp[sy][sx] + now.cost) {
					dp[ey][ex] = dp[sy][sx] + now.cost;
					if (i == w * h - g)
						flag = true;
				}
			}
		}

		if (flag) {
			cout << "Never\n";
		}
		else if (dp[h - 1][w - 1] == INF) {
			cout << "Impossible\n";
		}
		else {
			cout << dp[h - 1][w - 1] << '\n';
		}

		edgelist.clear();
	}
}