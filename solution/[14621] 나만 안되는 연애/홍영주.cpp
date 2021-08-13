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

		// MST 특성 사용
		if (cnt == N - 1) break;

		// 연결이 되어있지 않고, start와 end의 대학교가 서로 다른 성별이 다른 대학교여야된다.
		if (Find(now.start) != Find(now.end) && gender[now.start] != gender[now.end]) {
			Union(now.start, now.end);
			cnt++;
			sum += now.cost;
		}
	}

	// MST 가 완성되었다.
	if (cnt == N - 1) {
		cout << sum << "\n";
	}// 연결이 안되었다 ㅠㅠ..
	else {
		cout << -1 << "\n";
	}

	return 0;
}