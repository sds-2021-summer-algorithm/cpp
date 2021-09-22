/**********************************************************************
작성일 : 2021-09-22
작성자 : 윤연상
문제 :
	작년 순위와 상대적인 순위가 바뀐 모든 팀의 목록이 주어진다.
	이때 올해의 순위를 출력하거나, 데이터에 일관성이 없으면 IMPOSSIBLE을 출력
	2 ≤ n(팀수) ≤ 500, 0 ≤ m(바뀌는 횟수) ≤ 25000
풀이 :
	위상정렬임을 파악하는 데에 시간이 걸리고 구현은 크게 어렵지 않았음.
	작년 순위를 단방향 그래프로 만들고, 순위가 바뀌는 것은 해당 간선의 방향을 바꿔준다.
	바뀌는 횟수가 총 25000번이라 adjlist에 접근하는 시간을 줄이기 위해 2차원배열을 사용(random access)
	바뀐 그래프를 위상정렬을 통해 순위를 구함(if 사이클이 있으면 데이터 오류 => IMPOSSIBLE)
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n^2)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int tc;
int n, m;
int inDegree[501];
int adjlist[501][501];

void init() {		// 데이터 초기화
	fill(inDegree, inDegree + 501, 0);
	for (int i = 0; i < 501; i++) {
		fill(adjlist[i], adjlist[i] + 501, 0);
	}
}

void input() {
	vector<int> teams;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int team; cin >> team;
		inDegree[team] = n - 1 - i;
		teams.push_back(team);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			adjlist[teams[j]][teams[i]] = 1;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;

		if (adjlist[a][b] == 1) {	// 간선 방향을 바꾼다(진입 차수도 수정)
			adjlist[a][b] = 0;
			adjlist[b][a] = 1;
			inDegree[a]++;
			inDegree[b]--;
		}
		else {
			adjlist[a][b] = 1;
			adjlist[b][a] = 0;
			inDegree[a]--;
			inDegree[b]++;
		}
	}
}
void print_new_rank() {
	stack<int> ans;
	queue<int> q;

	for (int i = 1; i <= n; i++) {	// 위상정렬 수행
		if (inDegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int now = q.front(); q.pop();
		ans.push(now);

		for (int i = 1; i <= n; i++) {
			if (adjlist[now][i] == 1) {
				if (--inDegree[i] == 0) {
					q.push(i);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {	// 사이클 존재 여부 확인
		if (inDegree[i] > 0) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}

	while (!ans.empty()) {			// 순위 출력
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << '\n';
	return;
}

int main(void) {
	fastio;

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();
		input();
		print_new_rank();
	}

	return 0;
}