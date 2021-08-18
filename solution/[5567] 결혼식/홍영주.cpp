#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> checked;
vector<vector<int>> adj;
int cnt = 0;

void BFS(int index) {
	
	queue<int> q;

	// 시작점은 1로
	checked[index] = 1;

	q.push(index);


	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (checked[now] == 3) break;

		int len = adj[now].size();
		// 방문, 순회할 수 있는가?

		for (int i = 0; i < len; i++) {
			int next = adj[now][i];

			if (checked[next] == 0) {
				q.push(next);
				cnt++;
				checked[next] = checked[now] + 1;
			}
		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	int M;

	cin >> N >> M;

	adj = vector<vector<int>>(N + 1, vector<int>());
	checked = vector<int>(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;

		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	BFS(1);


	cout << cnt << "\n";
	return 0;
}