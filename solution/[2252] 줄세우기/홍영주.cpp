#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int a;
	int b;

	Edge(int a, int b) {
		this->a = a;
		this->b = b;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<Edge>> edges(N + 1);
	vector<int> inherit(N + 1, 0 );
	queue<int> q;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(Edge(a, b));
		inherit[b]++;
	}

	// 초기 inherit이 0인 것들을 큐에 넣기
	for (int i = 1; i < inherit.size(); i++) {
		if (inherit[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " ";

		int size = edges[now].size();
		for (int i = 0; i < size; i++) {
			int next = edges[now][i].b;

			inherit[next]--;
			if (inherit[next] == 0) {
				q.push(next);
			}
		}
	}
	return 0;


}