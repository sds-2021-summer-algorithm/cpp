/**********************************************************************
작성일 : 2021-09-13
작성자 : 윤연상
문제 :
	두명씩의 키 순서가 주어질 때 전체 친구들의 키순서를 출력
	A B => A가 B 앞에서야함 => A->B
	N(1 ≤ N ≤ 32,000), M(1 ≤ M ≤ 100,000)
풀이 :
	위상정렬을 사용해 키 순서를 출력한다.
	어떠한 결과를 출력해도 상관 없다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n+m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m;
int inDegree[32001];
vector<int> adjlist[32001];

void input() {
	cin >> n >> m;
	memset(inDegree, 0, sizeof(inDegree));

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adjlist[a].push_back(b);
		inDegree[b]++;
	}
}

vector<int> DAG() {
	vector<int> ret;

	queue<int> q;
	for (int i = 1; i <= n; i++) {	// 진입차수 0인 것을 queue에 push
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {			// 위상 정렬 수행
		int now = q.front(); q.pop();

		ret.push_back(now);

		for (int& nex : adjlist[now]) {
			if (--inDegree[nex] == 0)
				q.push(nex);
		}
	}

	return ret;
}

int main(void) {
	fastio;

	input();	// 입력 받기

	vector<int> result = DAG();	// 위상정렬 수행

	for (int& i : result) {		// 키순서 출력
		cout << i << ' ';
	}

	return 0;
}