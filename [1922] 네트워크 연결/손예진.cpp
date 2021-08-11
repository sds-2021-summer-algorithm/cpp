#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct node {
	int a, b, cost;
};

struct cmp {
	bool operator() (node &n1, node &n2){
		return n1.cost > n2.cost;
	}
};

priority_queue<node, vector<node>, cmp> pq;
int ans, cnt, N, M, dist[1001];
int parent[1001];

int Find(int n) {	//부모 반환
	if (parent[n] == n)
		return n;
	return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {	//a와 b합치기
	int pa = Find(a);
	int pb = Find(b);
	if (pa != pb)
		parent[pb] = pa;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a, b, c });
	}

	//initialize parent
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	//(cost 작은 순으로) 동일한 그룹에 속해있다면 continue, 다르다면 union 한 뒤 cost 더해주기
	while (!pq.empty()) {
		node n = pq.top();
		pq.pop();
		int a = n.a, b = n.b, cost = n.cost;
		if (a == b)
			continue;
		if (Find(a) != Find(b)) {
			Union(a, b);
			ans += cost;
			cnt++;
		}
		if (cnt == N - 1)	//모든 정점을 연결하기 위한 최소 간선 개수를 만족시킴
			break;
	}
	cout << ans << "\n";
}
