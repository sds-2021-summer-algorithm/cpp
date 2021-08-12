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

	while (1) {
		int N, M;
		cin >> N >> M;

		if (N == 0 && M == 0) {
			return 0;
		}

		parent = vector<int>(N);
		priority_queue<Edge, vector<Edge>, compare> pq;

		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}

		long long total = 0;
		for (int i = 0; i < M; i++) {
			int a, b;
			long long c;

			cin >> a >> b >> c;
			if (a < N && b < N) {
				total += c;
				pq.push(Edge(a, b, c));
			}
		}

		long long sum = 0;
		int cnt = 0;
		while (!pq.empty()) {
			Edge now = pq.top();
			pq.pop();

			// MST 특징
			if (cnt == N - 1) break;

			// 연결되어 있지 않으면 연결시킨다.
			if (Find(now.start) != Find(now.end)) {
				Union(now.start, now.end);
				cnt++;
				sum += now.cost;
			}

		}

		cout << total - sum << "\n";
	}
	
}