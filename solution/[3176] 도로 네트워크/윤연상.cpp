/**********************************************************************
작성일 : 2021-09-03
작성자 : 윤연상
문제 :
	- 두 도시를 가는 경로 중 최대 간선, 최소 간선을 구하는 문제
	- 2 <= N(노드수) <= 100000, 1 <= K(쿼리수) <= 100000
풀이 :
	- 모든 노드는 서로 연결되어있고 간선 수는 N-1개 => 반드시 트리임! (사이클이 존재할 수 없음)
	- n, k 모두 최대 100000이기 때문에 O(n^2)은 시간초과 => 각 쿼리를 반드시 O(logn) 이내에 구해야함
	- 트리 내에서 두 노드의 경로에는 반드시 최소공통조상(LCA)이 있다는 것을 이용함
	- 기본 LCA에서 두 가지를 추가해 응용함 
	- Max[i][node], Min[i][node] : node에서 2^i번째 조상까지의 최대, 최소 간선
		=> 점화식 : Max[i][node] = max(Max[i-1][node], Max[i-1][parent[i-1][node]) (min도 동일)
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O((n+k)logn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2000000000
#define Pmax 20
#define Node 100000

using namespace std;
typedef pair<int, int> pii;

int n, k;
int depth[Node + 1];
int parent[Pmax + 1][Node + 1];
int Max[Pmax + 1][Node + 1];
int Min[Pmax + 1][Node + 1];

struct edge {
	int end, cost;
	edge(int _end, int _cost) : end(_end), cost(_cost) {};
};
vector<edge> adjlist[Node + 1];

void breakpoint() {
	cout << "break\n";
}

void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		adjlist[a].push_back(edge(b, c));
		adjlist[b].push_back(edge(a, c));
	}
}
void dfs(int cur, int cnt) {
	depth[cur] = cnt;
	
	for (edge& e : adjlist[cur]) {
		if (depth[e.end] != 0)
			continue;
		dfs(e.end, cnt + 1);
		parent[0][e.end] = cur;
		Max[0][e.end] = e.cost;
		Min[0][e.end] = e.cost;
	}
}
void init() {
	input();
	
	dfs(1, 1);

	Max[0][1] = -INF;	// root위는 선택되지 않도록 설정
	Min[0][1] = INF;

	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			Max[i][j] = max(Max[i - 1][j], Max[i - 1][parent[i - 1][j]]);
			Min[i][j] = min(Min[i - 1][j], Min[i - 1][parent[i - 1][j]]);
		}
	}
}
pii LCA(int a, int b) {
	int max_edge = -INF;
	int min_edge = INF;

	if (depth[a] < depth[b]) swap(a, b);


	for (int i = Pmax; i >= 0; i--) {
		if ((1 << i) <= n && depth[a] - (1 << i) >= depth[b]) {
			max_edge = max(max_edge, Max[i][a]);	// max, min 값 갱신 후 node 갱신
			min_edge = min(min_edge, Min[i][a]);
			a = parent[i][a];
		}
	}
	

	if (a == b) return make_pair(min_edge, max_edge);

	for (int i = Pmax; i >= 0; i--) {
		if ((1 << i) <= n && parent[i][a] != parent[i][b]) {
			max_edge = max(max_edge, max(Max[i][a], Max[i][b]));	// max, min 값 갱신 후 node 갱신
			min_edge = min(min_edge, min(Min[i][a], Min[i][b]));
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	
	max_edge = max(max_edge, max(Max[0][a], Max[0][b]));
	min_edge = min(min_edge, min(Min[0][a], Min[0][b]));

	return make_pair(min_edge, max_edge);
}

int main(void) {
	fastio;

	init();		// 초기화 

	cin >> k;	
	for (int i = 0; i < k; i++) {	// query 수행
		int a, b; cin >> a >> b;
		pii ret = LCA(a, b);

		cout << ret.first << ' ' << ret.second << '\n';
	}

	return 0;
}