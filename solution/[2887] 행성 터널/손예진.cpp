#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
* <idea>
* 행성들간의 MST를 구하는 문제. 그러나 모든 행성간의 거리를 계산해주면 3*1e10으로 시간초과 발생
* 굳이 모든 행성간의 거리 계산할 필요 없음. 가장 인접한 행성과의 거리만 알면 됨.
* 따라서 x값, y값, z값 각각에 대해 가장 인접한 행성과의 거리만 계산해서 priority_queue에 넣어줌
* 이때 x, y, z 중 최소 거리가 뭔지 알 필요 없음. 
* => 가장 작은 값은 이미 pq의 가장 앞에 배치됨 && union으로 연결됨 -> 그 뒤에 나오는 더 큰 거리는 무시됨.
*/

typedef struct edge {
	int a, b;
	long long c;
};

struct cmp {
	bool operator()(edge& e1, edge& e2) {
		return e1.c > e2.c;
	}
};

priority_queue<edge, vector<edge>, cmp> pq;
vector<pair<long long, int>> X, Y, Z;
int N, parent[100001];

int Find(int n) {
	if(parent[n] == n)
		return n;
	return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa != pb)
		parent[pb] = pa;
}

void CalcDist() {	//각 x, y, z 값에 대해 인접한 행성들 간의 거리 계산 -> pq에 push
	for (int i = 0; i < N - 1; i++) {
		pq.push({ X[i].second, X[i + 1].second, X[i + 1].first - X[i].first });
		pq.push({ Y[i].second, Y[i + 1].second, Y[i + 1].first - Y[i].first });
		pq.push({ Z[i].second, Z[i + 1].second, Z[i + 1].first - Z[i].first });
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		long long x, y, z;
		cin >> x >> y >> z;
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());
	CalcDist();

	//initialize parent
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	int cnt = 0;
	long long cost = 0;
	while (!pq.empty()) {
		if (cnt == N - 1)
			break;
		int a = pq.top().a, b = pq.top().b;
		long long c = pq.top().c;
		pq.pop();
		if (a == b || Find(a) == Find(b))
			continue;
		Union(a, b);
		cost += c;
		cnt++;
	}
	cout << cost << "\n";
}
