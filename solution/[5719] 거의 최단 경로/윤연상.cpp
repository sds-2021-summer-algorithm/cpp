/*
* 상당히 오래 걸리고 어려운 문제....
* 일단 최단 거리 문제여서 다익스트라, 벨만 포드, 플로이드 워셜 중 선택
* 출발지와 도착지가 고정되어있고 음의 간선이 없기 때문에 '다익스트라'를 선택
* 보통 다익스트라는 dist[next] > dist[now] + cost 와 같이 거리가 갱신되는 경우에만 heap 넣지만,
* 이 문제는 모든 최단 거리를 고려해야하기 때문에 dist[next] == dist[now] + cost의 경우도 고려
* dist배열이 갱신될 때 마다 parent라는 역추적 간선배열에 추가함
* 다익스트라 한번 돌리고 난 뒤 역추적 배열을 기준으로 bfs를 돌려서 최단 거리 간선을 삭제!
*/

#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

int n, m;
int s, d;
int adjlist[501][501];		// 인접행렬(vector가 아닌 이차원 배열로 한번 써봤음)
bool visited[501][501];		// bfs를 위한 visited 배열(간선 체크)
vector<int> parent[501];	// 최단 경로 기록을 위한 parent 배열

struct node {
	int id, dist;
	node(int _i, int _d) :id(_i), dist(_d) {};
};
struct cmp {
	bool operator()(node& a, node& b) {
		return a.dist > b.dist;
	}
};
priority_queue<node, vector<node>, cmp> pq;

// input 함수(0 0 입력 시 코드 종료)
bool _input() {
	cin >> n >> m;
	if (n == 0 && m == 0) 
		return false;
	
	cin >> s >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			adjlist[i][j] = -1;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adjlist[a][b] = c;
	}

	return true;
}
// parent 배열을 비우는 용도(vector 특성)
void _clear() {
	for (int i = 0; i < n; i++) {
		parent[i].clear();
		vector<int>().swap(parent[i]);
	}
}
// 다익스트라(isfirst는 첫 번째로 호출되는 함수인지 체크)
int dijkstra(bool isfirst) {
	int dist[501];
	fill(dist, dist + n, INF);
	
	dist[s] = 0;
	pq.push(node(s, 0));

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		for (int i = 0; i < n; i++) {
			if (adjlist[now.id][i] == -1)
				continue;

			int new_dist = dist[now.id] + adjlist[now.id][i];
			if (dist[i] > new_dist) {
				dist[i] = new_dist;
				pq.push(node(i, new_dist));
				if (isfirst) {
					parent[i].clear();
					parent[i].push_back(now.id);
				}
			}
			else if (dist[i] == new_dist && isfirst) {
				parent[i].push_back(now.id);
			}
		}
	}

	if (dist[d] == INF)
		return -1;
	else
		return dist[d];
}
// bfs를 통해 도착지에서 출발지까지의 최단 거리를 다 지움
void remove_parent() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
	deque<int> q;

	q.push_back(d);

	while (!q.empty()) {
		int now = q.front(); q.pop_front();
		for (int& next : parent[now]) {
			if (visited[now][next])
				continue;
			visited[now][next] = true;
			adjlist[next][now] = -1;
			q.push_back(next);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (_input()) {

		dijkstra(true);			// 최단거리 찾음
		remove_parent();		// 최단거리 지움
		cout << dijkstra(false) << '\n';	// 거의 최단거리 찾음

		_clear();
	}

	return 0;
}