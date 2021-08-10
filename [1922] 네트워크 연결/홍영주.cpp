#include <iostream>
#include <vector>
#include <queue>

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
	// pa = parent[a]가 아니라 Find(a)이다. 왜냐하면, a의 궁극적인 부모를 찾아야 되기 때문!!
	int pa = Find(a);
	int pb = Find(b);

	parent[pb] = pa;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	int M;
	cin >> N;
	cin >> M;

	// 컴퓨터의 수 N개 이면 자신의 부모를 표현할 수 있는 배열을 N개 만든다
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
		Edge e = pq.top();
		pq.pop();

		// MST의 특징 간선의 개수는 V(정점의 개수)-1 이다.
		if (cnt == N - 1) break;

		// 연결이 되어있지 않으면
		if (Find(e.start) != Find(e.end)) {
			Union(e.start, e.end);
			cnt++;
			sum += e.cost;
		}
	}
	cout << sum << "\n";

	return 0;
}