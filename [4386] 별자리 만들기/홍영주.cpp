#include <iostream>
#include <vector>
#include <queue>
#include <cmath>


using namespace std;

vector<int> parent;

struct star {
	int num;
	double x;
	double y;

	star(int num, double y, double x) {
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

	int N;
	cin >> N;

	parent = vector<int>(N + 1);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	vector<star> stars;
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		stars.push_back(star(i + 1, y, x));
	}

	priority_queue<Edge, vector<Edge>, compare> pq;

	for (int i = 0; i < stars.size() -1; i++) {
		for (int j = i + 1; j < stars.size(); j++) {
			double cost = sqrt(pow(stars[i].x - stars[j].x, 2) + pow(stars[i].y - stars[j].y, 2));
			pq.push(Edge(i+1, j+1, cost));
		}
	}
	
	double sum = 0.0L;
	int cnt = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		// MST 의 특징 간선의 개수는 N-1개이다.
		if (cnt == N - 1) break;

		if (Find(now.start) != Find(now.end)) {
			Union(now.start, now.end);
			cnt++;
			sum += now.cost;
		}
	}
	cout << (round(sum *100) / 100) << "\n";
	
	return 0;
}