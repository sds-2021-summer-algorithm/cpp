#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> parent;

struct Edge {
	int start;
	int end;
	int cost;

	Edge(int start, int end, int cost){
		this->start = start;
		this->end = end;
		this->cost = cost;
	}
};

struct compare {
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

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	priority_queue<Edge, vector<Edge>, compare> pq;


	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		pq.push(Edge(a, b, c));
	}

	int cnt = 0;
	int sum = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		// 최소 스패닝 트리를 만들고 도시를 2개 분할해야되므로 !!
		// N-2개 만큼!!
		if (cnt == N - 2) break;

		// 연결 되어있지 않으면?
		if (Find(now.start) != Find(now.end)) {
			cnt++;
			sum += now.cost;
			Union(now.start, now.end);
		}

	}
	cout << sum << "\n";

	return 0;
}