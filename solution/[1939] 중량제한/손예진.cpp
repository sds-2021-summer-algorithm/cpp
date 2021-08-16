#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1000000001

using namespace std;

//dist: A -> B로 가는데 거치는 경로 중 다리 무게 제한의 최솟값의 최댓값

int N, M, A, B, max_limit;
int dist[10001];
vector<pair<int, int>> graph[10001];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ MAX, A });
	while (!pq.empty()) {
		int now = pq.top().second;	//다음 탐색할 노드
		int cost = pq.top().first;	//now까지 오는데 필요한 최소 제한 중량
		pq.pop();
		if (dist[now] > cost) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].second;
			long long next_cost = min( graph[now][i].first, cost);
			if (dist[next] < next_cost) {
				dist[next] = next_cost;
				pq.push({ next_cost, next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}
	cin >> A >> B;
	dijkstra();
	cout << dist[B];
}
