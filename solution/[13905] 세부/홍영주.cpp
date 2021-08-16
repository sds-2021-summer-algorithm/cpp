#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1000001

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
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	parent = vector<int>(N + 1);
	priority_queue<Edge, vector<Edge>, compare> pq;


	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	
	int s, e;

	cin >> s >> e;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		pq.push(Edge(a, b, c));
	}


	int answer = MAX;
	bool isPossible = false;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		// 연결이 되어있지 않으면
		if (Find(now.start) != Find(now.end)) {
			Union(now.start, now.end);
			answer = min(answer, now.cost);
		}

		// 목적지와 출발지 연결됨
		if (Find(s) == Find(e)) {
			isPossible = true;
			break;
		}
	}

	if (isPossible) {
		cout << answer;
	}
	else {
		cout << 0;
	}
	return 0;
}