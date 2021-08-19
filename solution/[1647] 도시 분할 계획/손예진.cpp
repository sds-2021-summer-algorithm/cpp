#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
* <idea>
* 어차피 MST를 만드는 동안 cost가 가장 작은 간선부터 탐색
* -> (N - 2)개의 정점이 연결되는 동안 최소한의 cost만 발생함
* -> 마지막 정점 하나를 연결하기 위해서는 최대의 cost가 발생 때문에 다른 마을로 배치하면 최소한의 cost로 두 마을에 대한 MST 생성 가능
* => 즉 N - 2 개의 정점에 대한 MST의 cost를 구하는게 답
*/

int N, M;

typedef struct edge {
	int a, b, c;
};

struct cmp {
	bool operator()(edge& e1, edge& e2) {
		return e1.c > e2.c;
	}
};

priority_queue<edge, vector<edge>, cmp> pq;
int parent[100001];

int Find(int n) {
	if (parent[n] == n)
		return n;
	return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa != pb)
		parent[pb] = pa;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a, b, c });
	}

	//initialize parent
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	int cnt = 0, cost = 0;
	while (!pq.empty()) {
		int a = pq.top().a, b = pq.top().b, c = pq.top().c;
		pq.pop();
		if (cnt == N - 2)
			continue;
		if (a == b || Find(a) == Find(b))
			continue;
		Union(a, b);
		cnt++;
		cost += c;
	}
	cout << cost << "\n";
}
