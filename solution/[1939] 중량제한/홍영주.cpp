#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> parent;

struct Edge {
	int start;
	int end;
	int cost;

	Edge(int start, int end, int cost) {
		this->start = start;
		this->end = end;
		this->cost = cost;
	}
};

struct compare {
	bool operator()(Edge a, Edge b) {
		return a.cost < b.cost;
	}
};

int Find(int i) {
	if (parent[i] == i) return i;
	else {
		return parent[i] = Find(parent[i]);
	}
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	parent[pb] = pa;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	parent = vector<int>(N + 1);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	priority_queue<Edge, vector<Edge>, compare> pq;

	for (int i = 0; i < M; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		pq.push(Edge(a, b, c));
	}

	int start, end;
	cin >> start >> end;
	int max_cost = 2000000000;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (Find(start) == Find(end)) {
			break;
		}

		Union(now.start, now.end);
		
		max_cost = min(max_cost, now.cost);
	}

	cout << max_cost << "\n";
}