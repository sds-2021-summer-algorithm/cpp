#include <iostream>
#include <vector>
#include <algorithm>
#define Pmax 16

using namespace std;

int N, M, depth[50001], parent[50001][Pmax];
vector<int> graph[50001];

//내 모든 조상 관계 정리
void SetParent() {
	for (int i = 1; (1 << i) < N; i++) {
		for (int j = 1; j <= N; j++) {	//1~N에 대해 각자 2의 1 ~ k (2^k <= N) 승의 부모 찾기
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
}

void SetDepth(int idx, int p, int d) {
	depth[idx] = d;
	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];
		if (next != p) {
			parent[next][0] = idx;
			SetDepth(next, idx, d + 1);
		}
	}
}

int LCA(int a, int b) {
	//항상 a의 depth가 b의 depth보다 크도록 유지
	if (depth[a] < depth[b])
		swap(a, b);
	//depth 동일하도록 위치 조정
	if (depth[a] != depth[b]) {
		for (int i = Pmax; i >= 0; i--) {	//2진수로, a와 b depth차이 표현
			if (depth[a] - (1 << i) >= depth[b])	//-> ex) i = 3, 1, 0일 때 if문에 해당한다면 둘의 차이는 2^3 + 2^1 + 2^0 = 11
				a = parent[a][i];
		}
	}
	if (a == b)
		return a;
	for (int i = Pmax; i >= 0; i--) {
		if (depth[a] - (1 << i) >= 0 && parent[a][i] != parent[b][i]) {	//a와 b가 동일해지지 않는 최대의 위치
			a = parent[a][i];
			b = parent[b][i];
		}
	};
	return parent[a][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	SetDepth(1, 0, 0);
	SetParent();
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
}
