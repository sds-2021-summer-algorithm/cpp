#include <iostream>
using namespace std;

// "여행 가자"
// * union find 관련 문제
// https://www.acmicpc.net/problem/1976

int parent[201];

int n, m;
int plan[1001];

int answer;

int find(int a) {
	if (a == parent[a]) return a;

	return parent[a] = find(parent[a]);
}

void unionCity(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);

	parent[aRoot] = bRoot;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) parent[i] = i;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int connect; cin >> connect;

			// 연결되어 있으면
			if (connect == 1) {
				unionCity(i, j);
			}
		}
	}
	for (int i = 0; i < m; ++i) cin >> plan[i];

	bool isAble = true;
	int ret = find(plan[0]);
	for (int i = 1; i < m; ++i) {
		if (ret == find(plan[i])) {
			ret = find(plan[i]);
		}
		else { isAble = false; break; }
	}

	if (isAble) cout << "YES";
	else cout << "NO";

	return 0;
}