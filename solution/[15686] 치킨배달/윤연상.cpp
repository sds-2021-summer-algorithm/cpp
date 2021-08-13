/*
* 완전탐색 구현
* => dfs를 통해 완전탐색 구현
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int num = 0;
int dist = INT_MAX;

struct pos {
	int y, x;
	bool selected;
	pos(int _y, int _x, bool _s) : y(_y), x(_x), selected(_s) {};
};
deque<pos> chicken;		// 치킨집 배열
deque<pos> house;		// 집 배열

// 각 집 기준으로 치킨거리를 계산 후 리턴
int check_dist(){		
	int retval = 0;
	for (pos& h : house) {
		int tmp = INT_MAX;
		for (pos& c : chicken) {
			if (!c.selected) continue;
			tmp = min(tmp, abs(h.y - c.y) + abs(h.x - c.x));
		}
		retval += tmp;
	}
	return retval;
}

// 치킨집 개수 - m 만큼 폐업 시킴(pos.selected = false 가 폐업 상태)
void dfs(int cnt, int idx) {
	if (cnt == num - m) {
		dist = min(dist, check_dist());
		return;
	}

	for (int i = idx; i < (int)chicken.size();i++) {
		if (!chicken[i].selected) {
			continue;
		}
		chicken[i].selected = false;
		dfs(cnt + 1, i);
		chicken[i].selected = true;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			if (tmp == 1) {
				house.push_back(pos(i, j, true));
			}
			else if (tmp == 2) {
				chicken.push_back(pos(i, j, true));
				num++;
			}
		}
	}

	dfs(0, 0);

	cout << dist;
}