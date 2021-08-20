/*
* 각 물품의 무게 비교를 계속하면서 출력해야함
* Union - find 응용
* 서로소 집합을 나타내는 parent배열과 부모와의 무게 차이를 저장하는 diff 배열
* 
* diff[a] : a와 a 부모의 무게 차이
* find를 수행하면서 parent와 diff를 계속 바꿔준다.
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int parent[100001];
ll diff[100001];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		diff[i] = 0;
	}
}
int find(int n) {
	if (parent[n] == n) return n;

	int pa = find(parent[n]);		// 부모의 find 재귀호출
	diff[n] += diff[parent[n]];		// 이미 부모의 diff도 쭈욱 바뀌어있음

	return parent[n] = pa;
}
void merge(int n1, int n2, ll weight) {
	int p1 = find(n1);
	int p2 = find(n2);

	if (p1 == p2) return;

	parent[p1] = p2;
	diff[p1] = diff[n2] - diff[n1] + weight;
}

bool solve() {
	cin >> n >> m;
	if (n == 0 && m == 0) return false;

	init(n);

	for (int i = 0; i < m; i++) {
		char c; cin >> c;
		
		if (c == '!') {
			int n1, n2; ll w;
			cin >> n1 >> n2 >> w;
			merge(n1, n2, w);
		}
		else if (c == '?') {
			int n1, n2;
			cin >> n1 >> n2;
			
			if (find(n1) == find(n2))
				cout << diff[n1] - diff[n2] << '\n';
			else
				cout << "UNKNOWN\n";
		}
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		if (!solve()) break;
	}
}