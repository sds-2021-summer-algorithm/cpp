#include <iostream>
#include <vector>
#include <queue>
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

struct compare2 {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
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
	priority_queue<Edge, vector<Edge>, compare> pq1;
	priority_queue<Edge, vector<Edge>, compare2> pq2;

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	int entry;
	for (int i = 0; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 1) {
			entry = c;
			continue;
		}

		if (a == 1 && b == 0) {
			entry = c;
			continue;
		}


		// 계산하기 편하기 (오르막길을)0->1, (내리막길을) 1->0으로 치환하여 넣는다.
		pq1.push(Edge(a, b,  c));
		pq2.push(Edge(a, b, c));
	}

	int cnt = 0;
	int cnt_MIN = 0;
	if (entry == 0) cnt_MIN++;

	Union(0, 1);
	while (!pq1.empty()) {
		Edge now = pq1.top();
		pq1.pop();

		if (cnt == N-1) break;

		if (Find(now.start) != Find(now.end)) {
			if (now.cost == 0) cnt_MIN++;
			Union(now.start, now.end);
			cnt++;
		}
	}

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	int cnt2 = 0;
	int cnt_MAX = 0;
	if (entry == 0) cnt_MAX++;
	Union(0, 1);

	while (!pq2.empty()) {
		Edge now = pq2.top();
		pq2.pop();

		if (cnt2 == N -1) break;

		if (Find(now.start) != Find(now.end)) {
			if (now.cost == 0) cnt_MAX++;
			
			Union(now.start, now.end);
			cnt2++;
		}
	}

	cout << (cnt_MAX * cnt_MAX) - (cnt_MIN * cnt_MIN) << "\n";

	
	return 0;
}