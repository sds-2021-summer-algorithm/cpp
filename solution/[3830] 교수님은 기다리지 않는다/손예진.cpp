#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, parent[100001];
long long dist[100001];

pair<int, long long> Find(int n) {  //parent와 dist값 갱신
	if (parent[n] == n)
		return {n, 0};
	pair<int, long long> p = Find(parent[n]);
	parent[n] = p.first;
	dist[n] += p.second;
	return { parent[n], dist[n] };
}

void Union(int a, int b, long long w) {
	int pa = Find(a).first;
	int pb = Find(b).first;
	if (pa != pb) {
		int height_a = dist[a];
		int height_b = dist[b] - w;
		if (height_a > height_b) {  //height가 더 높은 쪽이 부모가 돼야됨 (모든 dist값이 음수이기 때문에 높다 == 작다)
			parent[pa] = pb;
			dist[pa] = height_b - height_a;
		}
		else {
			parent[pb] = pa;
			dist[pb] = height_a - height_b;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)	//종료조건
			return 0;

		for (int i = 1; i <= N; i++)	//부모 초기화
			parent[i] = i;
		memset(dist, 0, sizeof(dist));

		for (int i = 0; i < M; i++) {
			char q;
			int a, b;
			long long w;
			cin >> q >> a >> b;
			switch (q)
			{
			case '!':
				cin >> w;
				if (w < 0) {  //w는 무조건 음수가 되도록
					swap(a, b); w *= -1;
				}
				Union(a, b, w);
				break;
			case '?':
				if (Find(a).first == Find(b).first) {
					long long ans = dist[b] - dist[a];
					cout << ans << "\n";
				}
				else
					cout << "UNKNOWN\n";
				break;
			}
		}
	}

}
