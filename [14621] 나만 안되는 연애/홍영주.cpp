#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent;
vector<char> gender;

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
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	parent = vector<int>(N + 1);
	gender = vector<char>(N + 1);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		cin >> gender[i];
	}

	priority_queue < Edge, vector<Edge>, compare> pq;

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

		// MST Ư�� ���
		if (cnt == N - 1) break;

		// ������ �Ǿ����� �ʰ�, start�� end�� ���б��� ���� �ٸ� ������ �ٸ� ���б����ߵȴ�.
		if (Find(now.start) != Find(now.end) && gender[now.start] != gender[now.end]) {
			Union(now.start, now.end);
			cnt++;
			sum += now.cost;
		}
	}

	// MST �� �ϼ��Ǿ���.
	if (cnt == N - 1) {
		cout << sum << "\n";
	}// ������ �ȵǾ��� �Ф�..
	else {
		cout << -1 << "\n";
	}

	return 0;
}