#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int N, M, start, fin;
int indegree[10001], dist[10001];
vector<pair<int, int>> graph[10001], back_track[10001];
queue<int> q;
set<pair<int, int>> s;

void BackTrack(int node, int parent) {
	s.insert({ node, parent });
	for (int i = 0; i < back_track[node].size(); i++) {
		int next = back_track[node][i].first, cost = back_track[node][i].second;
		if (next != start && dist[next] == 0)
			continue;
		if (dist[next] + cost == dist[node])
			BackTrack(next, node);
	}
}

void DAG() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first, cost = graph[now][i].second;
			int tmp = dist[now] + cost;
			if (tmp > dist[next]) {
				dist[next] = tmp;
			}
			else if (tmp == dist[next]) {

			}
			if (!--indegree[next])
				q.push(next);
		}
	}
	BackTrack(fin, -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		back_track[b].push_back({ a, c });
		indegree[b]++;
	}

	cin >> start >> fin;
	q.push(start);
	DAG();
	//BackTrack에 대한 결과 출력
	cout << dist[fin] << "\n" << s.size() - 1 << "\n";
}
