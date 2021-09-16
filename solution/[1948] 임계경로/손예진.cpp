#include <iostream>
#include <queue>
#include <vector>
#include <set>

/*
* <idea>
* 경로 역추적 방법: dist[next] + cost == dist[node];
* -> start 노드 ~ 모든 노드에 대한 dist 갱신되어 있기 때문에 이를 활용할 수 있음.
* <difficulty>
* 1. 메모리 초과
* 역추적 과정에서 이차원 배열로 경로 중복 여부 확인 -> set으로 해결
* 2. 시간 초과
* 이미 방문한 노드 재방문하여 이미 탐색한 경로 재탐색 
* -> node에 대한 visited 배열 사용 && 간선은 재방문 여부와 관계 없이 set에 추가
*/

using namespace std;

int N, M, start, fin;
int indegree[10001], dist[10001];
bool visited[10001];
vector<pair<int, int>> graph[10001], back_track[10001];
set<pair<int, int>> s;

void BackTrack(int node, int parent) {	//fin ~ 최종 갱신된 dist에 해당하는 모든 경로 역추적
	visited[node] = true;
	for (int i = 0; i < back_track[node].size(); i++) {
		int next = back_track[node][i].first, cost = back_track[node][i].second;
		if (next != start && dist[next] == 0)
			continue;
		if (dist[next] + cost == dist[node]) {	//해당되는 간선 back_track
			s.insert({ node, next });	//해당하는 모든 간선에 대해서는 방문 여부와 관계 없이 집합에 추가
			if(!visited[next])	//이미 방문한 노드는 다시 방문하지 않게 - [시간초과 원인]
				BackTrack(next, node);
		}
	}
}

void DAG() {	//start ~ 방문 가능한 모든 node에 대한 최대 dist 구하기
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first, cost = graph[now][i].second;
			int tmp = dist[now] + cost;
			if (tmp > dist[next]) {
				dist[next] = tmp;
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
	DAG();

	cout << dist[fin] << "\n" << s.size() << "\n";
}
