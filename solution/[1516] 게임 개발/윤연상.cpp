/**********************************************************************
작성일 : 2021-09-13
작성자 : 윤연상
문제 :
	각 건물을 짓기 위한 시간과 요구되는 건물이 주어진다.
	N개의 각 건물이 완성되기까지 걸리는 최소 시간을 출력한다.
	N(1 ≤ N ≤ 500), 각 건물을 짓는 최대 시간 100,000
풀이 :
	위상정렬을 통해 각 건물을 짓기위한 최소 시간을 계산
	여러 경로 중 최대 값을 선택해야함(해당 건물의 아래 건물을 다 지어야 해당 건물을 지을 수 있음)
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n+E)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
int inDegree[501];
int buildTime[501];
int totalBuildTime[501];
vector<int> adjlist[501];

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> buildTime[i];
		totalBuildTime[i] = buildTime[i];

		while (1) {
			int prev; cin >> prev;
			if (prev == -1) break;

			adjlist[prev].push_back(i);
			inDegree[i]++;
		}
	}
}

void DAG() {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		
		for (int& nex : adjlist[now]) {
			if (--inDegree[nex] == 0)
				q.push(nex);
			
			totalBuildTime[nex] = max(totalBuildTime[nex], totalBuildTime[now] + buildTime[nex]);
		}
	}
}

int main(void) {
	fastio;

	input();	// 입력
	DAG();		// 위상정렬 수행

	for (int i = 1; i <= n; i++) {
		cout << totalBuildTime[i] << '\n';	// 출력
	}

	return 0;
}