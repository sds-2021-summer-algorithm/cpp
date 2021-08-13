#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent;


struct Edge {
	int start;
	int end;
	long long cost;

	Edge(int start, int end, long long cost) {
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

	int N;
	cin >> N;
	
	parent = vector<int>(N + 1);

	priority_queue<Edge, vector<Edge>, compare> pq;
	

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			long long a;
			cin >> a;

			if (i == j || i > j) continue;
			else {
				pq.push(Edge(i, j, a));
			}
		}
	}

	int cnt = 0;
	long long sum = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (cnt == N - 1) break;

		// 연결되어있지 않으면
		if (Find(now.start) != Find(now.end)) {
			Union(now.start, now.end);
			cnt++;
			sum += now.cost;
		}
	}
	cout << sum;

	return 0;
	
}