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
	// pa = parent[a]�� �ƴ϶� Find(a)�̴�. �ֳ��ϸ�, a�� �ñ����� �θ� ã�ƾ� �Ǳ� ����!!
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

	// ��ǻ���� �� N�� �̸� �ڽ��� �θ� ǥ���� �� �ִ� �迭�� N�� �����
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

		// MST�� Ư¡ ������ ������ V(������ ����)-1 �̴�.
		if (cnt == N - 1) break;

		// ������ �Ǿ����� ������
		if (Find(e.start) != Find(e.end)) {
			Union(e.start, e.end);
			cnt++;
			sum += e.cost;
		}
	}
	cout << sum << "\n";

	return 0;
}