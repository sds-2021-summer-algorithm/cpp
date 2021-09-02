/**********************************************************************
작성일 : 2021-09-02
작성자 : 윤연상
문제 :
	주어진 트리안 두 노드의 최소공통조상을 구하는 문제 ( 기본 )
	root는 반드시 1
	2 <= N <= 50000, 1 <= M <= 10000
풀이 :
	기초적인 LCA 구현 문제 ( 2^i 를 (1 << i)로 표현하는 것을 배웠음 )
	초기화 단계 : depth -> parent 
	query 단계 : depth 맞추기 -> 탐색
시간 제한 : 3초
메모리 제한 : 256MB
예상 시간복잡도 : O(n+nlogn+mlogn) = O((n+m)logn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Pmax 20

using namespace std;

int n, m;					// n : 노드 수, m : query 수
int depth[50001];			// 각 노드의 depth
int parent[21][50001];		// 각 노드의 2^i번째 부모
vector<int> edge[50001];	// 트리의 간선

void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}

void dfs(int node, int dep) {
	depth[node] = dep;
	
	for (int& child : edge[node]) {
		if (depth[child] != 0)
			continue;
		dfs(child, dep + 1);
		parent[0][child] = node;
	}
}
void initLCA() {	// 초기 조건 설정
	input();
	dfs(1, 1);		// depth 구하기

	for (int i = 1; (1 << i) <= n; i++) {	//parent 배열 채우기
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
}
int LCA(int a, int b) {
	if (depth[a] < depth[b])
		swap(a, b);

	if (depth[a] != depth[b]) {
		for (int i = Pmax; i >= 0; i--) {
			if (depth[a] - (1 << i) >= depth[b])
				a = parent[i][a];
		}
	}

	if (a == b) return a;

	for (int i = Pmax; i >= 0; i--) {
		if (parent[i][a] != parent[i][b] && (1 << i) <= n) {
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	return parent[0][a];
}

int main(void) {
	fastio;

	initLCA();	// 초기화

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << LCA(a, b) << '\n';	// query 수행
	}

	return 0;
}