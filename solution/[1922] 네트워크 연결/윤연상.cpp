/*
* 모든 컴퓨터가 연결되고, 간선을 선택하는 비용이 최소여야함
* => 최소신장트리(MST)
* => 크루스칼 사용(union find && heap)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;			// n : 컴퓨터 개수, m : 간선 개수
int parent[1001];	// union find 용 부모 배열

struct edge {
	int n1, n2, cost;
	edge(int _n1, int _n2, int _cost) : n1(_n1), n2(_n2), cost(_cost) {};
};
struct compare {
	bool operator()(edge& a, edge& b) {
		return a.cost > b.cost;
	}
};
priority_queue<edge, vector<edge>, compare> pq;		// 간선의 cost 기준 heap

void init(int num) {
	// union find의 parent 배열 초기화
	for (int i = 1; i <= num; i++) {
		parent[i] = i;
	}
}
int find(int a) {
	// 노드 a의 부모(대장) 찾기
	if (parent[a] == a) {
		return a;
	}
	parent[a] = find(parent[a]);
	return parent[a];
}
void unionNode(int a, int b) {
	// 노드 a가 속한 집합과 노드 b가 속한 집합 합치기
	int pa = find(a);
	int pb = find(b);
	parent[pa] = parent[pb];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push(edge(a, b, c));
	}

	init(n);

	int cnt = 0; int ans = 0;
	while (cnt < n-1) {	// 간선은 무조건 n-1개
		edge now = pq.top(); pq.pop();

		if (find(now.n1) == find(now.n2)) {	// 해당 간선의 두 노드가 이미 같은 집합이면 건너뜀
			continue;
		}
		unionNode(now.n1, now.n2);			// 두 노드의 네트워크를 합침
		ans += now.cost;
		cnt++;
	}

	cout << ans;
}