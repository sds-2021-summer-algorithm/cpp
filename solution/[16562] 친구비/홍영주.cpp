#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> parent;

struct Friend {
	int cost;
	int id;

	Friend(int id, int cost) {
		this->id = id;
		this->cost = cost;
	}
};

struct compare {
	bool operator()(Friend a, Friend b) {
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

	if (pb > pa) {
		parent[pb] = pa;
	}
	else {
		parent[pa] = pb;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M, K;

	cin >> N >> M >> K;

	parent = vector<int>(N + 1);
	priority_queue<Friend, vector<Friend>, compare> pq;
	set<int> s;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		pq.push(Friend(i, num));
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		Union(a, b);
	}


	bool isOkay = false;
	int sum = 0;
	while (!pq.empty()) {
		Friend now = pq.top();
		pq.pop();

		//모두 연결이 되어있는가?
		bool isComplited = true;
		for (int i = 1; i <= N; i++) {
			if (Find(0) != Find(i)) {
				isComplited = false;
			}
		}

		if (isComplited) {
			isOkay = true;
			break;
		}


		// 연결 시도
		// 준석이는 0번이라고 생각하자
		// 연결이 안되어있으면
		if (Find(0) != Find(now.id)) {
			Union(0, Find(now.id));
			sum += now.cost;
		}
	}
	if (sum <= K) {
		cout << sum;
	}
	else {
		cout << "Oh no";
	}

	return 0;
}