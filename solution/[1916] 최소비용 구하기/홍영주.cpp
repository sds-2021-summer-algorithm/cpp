#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000

using namespace std;

struct Node {
	int id;
	int cost;

	Node(int id, int cost) {
		this->id = id;
		this->cost = cost;
	}
};


vector<vector<Node>> adj;

struct compare {
	bool operator()(Node a, Node b) {
		return a.cost > b.cost;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;

	cin >> N >> M;

	adj = vector<vector<Node>>(N + 1);
	vector<int> dist(N + 1, INF);
	priority_queue<Node, vector<Node>, compare> pq;

	for (int i = 1; i <= N; i++) {
		adj[i] = vector<Node>();
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		adj[a].push_back(Node(b, c));
	}

	int s, e;

	cin >> s >> e;
	dist[s] = 0;
	pq.push(Node(s, 0));

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		// 예전에 기록해두었던 거리보다 현재 비용이 더 크다면
		if (now.cost > dist[now.id]) continue;

		int len = adj[now.id].size();
		// 인접리스트 탐색
		for (int i = 0; i < len; i++) {
			Node next = adj[now.id][i];

			// 방문할 노드에 이전 기록된 것보다 현재 비용 + 다음 노드를 가는데 비용이 싸다면
			if (dist[next.id] > now.cost + next.cost) {
				dist[next.id] = now.cost + next.cost;
				pq.push(Node(next.id, dist[next.id]));
			}
		}
	}

	cout << dist[e] << "\n";

}