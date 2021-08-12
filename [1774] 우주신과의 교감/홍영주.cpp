#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> parent;

struct Vertex {
	int num;
	int x;
	int y;

	Vertex(int num ,int x, int y) {
		this->num = num;
		this->x = x;
		this->y = y;
	}
};

struct Edge {
	int start;
	int end;
	double cost;

	Edge(int start, int end, double cost) {
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

	vector<Vertex> v;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(Vertex(i, a, b));
	}

	priority_queue<Edge, vector<Edge>, compare> pq;

	// Edge 계산
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			double cost = sqrt(pow(v[i].x - v[j].x, 2) + pow(v[i].y - v[j].y, 2));
			pq.push(Edge(i + 1, j + 1, cost));
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	double sum = 0.0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();


		// MST 특성 사용 불가.. 그럼 다 연결되어있는지 확인이 필요!1.
		int temp = Find(1);
		bool isAll = true;
		for (int i = 2; i <= N; i++) {
			if (temp != Find(i)) {
				isAll = false;
				break;
			}
		}

		// 다 연결되어있으면 끝내기
		if (isAll) break;

		// 연결이 안되어있으면 연결시키기
		
		if (Find(now.start) != Find(now.end)) {
			Union(now.start, now.end);
			sum += now.cost;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << sum << "\n";

	return 0;

}