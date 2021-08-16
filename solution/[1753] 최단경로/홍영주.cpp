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

	int V, E;

	cin >> V >> E;

	int K;
	cin >> K;

	// 인접리스트 형태로 그래프를 표현하기
	adj = vector<vector<Node>>(V + 1);
	vector<int> dist(V+ 1, INF);
	priority_queue<Node, vector<Node>, compare> pq;

	for (int i = 1; i <= V; i++) {
		adj[i] = vector<Node>();
	}

	for (int i = 0; i < E; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		adj[a].push_back(Node(b, c));
	}

	dist[K] = 0;
	pq.push(Node(K, 0));

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		// 현재 비용이 예전에 기록되었던  목적지 비용보다 크다면 
		if (now.cost > dist[now.id]) continue;

		// 인접 리스트 탐색
		int len = adj[now.id].size();

		for (int i = 0; i < len; i++) {
			Node next = adj[now.id][i];
			if (dist[next.id] > now.cost + next.cost) {				
				dist[next.id] = now.cost + next.cost;

				pq.push(Node(next.id, dist[next.id]));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}


}