/**********************************************************************
작성일 : 2021-09-14
작성자 : 윤연상
문제 :
	모든 도로가 일방통행인 도로이고, 싸이클이 없다. 
	모든 사람이 도착 도시에서 만나기로 했을 때 모두 만나는 시간 => 최장거리
	최장거리의 길이와 최장거리 도로의 수를 카운트 하여라.
	1 ≤ n(도시) ≤ 10,000, 1 ≤ m(도로) ≤ 100,000
풀이 :
	일방통행, 사이클 없는 그래프 탐색 => '위상정렬'
	 - 각 도시로 가는 최장거리를 dist배열에 저장
	이후 역추적을 통해 최장거리에 사용된 간선을 찾는다 => 'bfs'
	 - dist[next] = dist[now] - cost
시간 제한 : 2초
메모리 제한 : 256MB
예상 시간복잡도 : O(n+m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m;		// n : 도시 개수, m : 도로 개수
int s, e;		// s : 출발 도시, e : 도착 도시
int dist[10001];
int inDegree[10001];
struct edge {
	int end, cost;
	bool isSelect;
	edge(int _end, int _cost, bool _b) : end(_end), cost(_cost), isSelect(_b) {};
};
vector<edge> adjlist[10001];
vector<edge> reverse_adjlist[10001];

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adjlist[a].push_back(edge(b, c, false));
		reverse_adjlist[b].push_back(edge(a, c, false));
		inDegree[b]++;
	}

	cin >> s >> e;
}

void DAG() {		// 위상정렬(최장거리 구하기)
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (edge& e : adjlist[now]) {
			if (--inDegree[e.end] == 0)
				q.push(e.end);

			dist[e.end] = max(dist[e.end], dist[now] + e.cost);
		}
	}
}

int get_road_cnt() {	// bfs(간선 찾기)
	int cnt = 0;

	queue<int> q;
	q.push(e);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (edge& e : reverse_adjlist[now]) {
			if (dist[e.end] == dist[now] - e.cost && !e.isSelect) {
				q.push(e.end);
				e.isSelect = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void) {
	fastio;

	input();	// 입력값 받기
	DAG();		// 각 도시의 도착 시간 구하기
	cout << dist[e] << endl << get_road_cnt();	// 간선 개수 구하기 및 출력

	return 0;
}