#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, parent[201];

int Find(int n) {
	if (parent[n] == n)
		return n;
	return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa != pb)
		parent[pa] = pb;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	//initialize parent
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int n;
			cin >> n;
			if (n && (Find(i) != Find(j))) {
				Union(i, j);
			}
		}
	}

	int common;
	for (int i = 0; i < M; i++) {	//모든 경로가 동일한 그룹에 속하면 여행 가능
		int n;
		cin >> n;
		if (i == 0)
			common = Find(n);
		else {
			if (common != Find(n)) {	//한 도시라도 동일한 그룹에 속하지 않는다면 여행 불가
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";	//여행 가능한 경로
}
