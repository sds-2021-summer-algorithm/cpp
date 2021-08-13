#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> parent;
struct Vertex {
	int num;
	int x;
	int y;
	int z;

	Vertex(int num, int x, int y, int z) {
		this->num = num;
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

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

bool comp1(Vertex a, Vertex b) {
	return a.x < b.x;
}

bool comp2(Vertex a, Vertex b) {
	return a.y < b.y;
}

bool comp3(Vertex a, Vertex b) {
	return a.z < b.z;
}

struct compare {
	bool operator()(Edge a, Edge b)
	{
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
	// 최종 부모를 찾기
	int pa = Find(a);
	int pb = Find(b);

	parent[pb] = pa;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	// 만약 행성의 개수가 1개라면 그냥 0으로 출력해준다.
	if (N == 1) {
		cout << 0 << "\n";
		return 0;
	}

	vector<Vertex> v;
	priority_queue<Edge, vector<Edge>, compare> pq;
	parent = vector<int>(N + 1);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	
	for (int i = 1; i <= N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back(Vertex(i, x, y, z));
	}

	// x를 기준으로 정렬
	sort(v.begin(), v.end(), comp1);

	for (int i = 0; i < v.size() - 1; i++) {
		int start = v[i].num;
		int end = v[i+1].num;
		pq.push(Edge(start, end, abs(v[i].x - v[i + 1].x)));
	}
	// y를 기준으로 정렬

	sort(v.begin(), v.end(), comp2);

	for (int i = 0; i < v.size() - 1; i++) {
		int start = v[i].num;
		int end = v[i + 1].num;
		pq.push(Edge(start, end, abs(v[i].y - v[i + 1].y)));
	}
	// z를 기준으로 정렬

	sort(v.begin(), v.end(), comp3);
	for (int i = 0; i < v.size() - 1; i++) {
		int start = v[i].num;
		int end = v[i + 1].num;
		pq.push(Edge(start, end, abs(v[i].z - v[i + 1].z)));
	}

	int cnt = 0;
	long long sum = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		// MST의 조건은 간선은 N-1개이다.
		if (cnt == N - 1) break;

		// 연결되어있지 않으면 연결시킨다.
		if (Find(now.start) != Find(now.end)) {
			Union(now.start, now.end);
			cnt++;
			sum += now.cost;
		}
		
	}

	cout << sum << "\n";

	return 0;
}