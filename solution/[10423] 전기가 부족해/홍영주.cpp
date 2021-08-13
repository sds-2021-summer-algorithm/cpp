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
	int pa = Find(a);
	int pb = Find(b);

	parent[pb] = pa;
}

int main() {
	int N, M, K;

	cin >> N >> M >> K;

	parent = vector<int>(N + 1);
	priority_queue<Edge, vector<Edge>, compare> pq;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	int norm;
	cin >> norm;

	for (int i = 1; i < K; i++) {
		int a;
		cin >> a; 
		Union(norm, a);
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push(Edge(a, b, c));
	}

	int sum = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		// MST 공식 사용 불가.. 모두 연결되었는지 확인 필요
		int index = Find(now.start);
		bool isConnect = true;
		for (int i = 1; i <= N; i++) {
			if (index != Find(i)) {
				isConnect = false;
				break;
			}
		}

		// 다 연결되어있으면 break
		if (isConnect) break;


		if (Find(now.start) != Find(now.end)) {
			Union(now.start, now.end);
			sum += now.cost;
		}
	}
	cout << sum << "\n";

	return 0;
}
