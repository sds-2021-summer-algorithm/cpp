#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct edge {
	int a, b;
	long long c;
};

struct cmp {
	bool operator()(edge& e1, edge& e2) {
		return e1.c > e2.c;
	}
};

int V, E, parent[10001];
priority_queue<edge, vector<edge>, cmp> pq;

int Find(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
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
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		pq.push({ a, b, c });
	}
	//initialize parent
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	int cnt = 0; long long cost = 0;
	while (!pq.empty()) {
		int a = pq.top().a; int b = pq.top().b; long long c = pq.top().c;
		pq.pop();
		if (a == b || Find(a) == Find(b))
			continue;
		Union(a, b);
		cost += c;
		if (++cnt == V - 1)
			break;
	}
	cout << cost << "\n";
}
