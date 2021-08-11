#include <iostream>
#include <queue>
using namespace std;

// 풀이 날짜 : 2021 08 11
// 체감 난이도 : 높았음(이유 : MST 개념 잊어버림..ㅎ)
// 문제 번호 : https://www.acmicpc.net/problem/1922

/* "N개의 노드를 연결하는 최소 비용은 N-1개의 간선으로 구성될 때 이뤄진다" 
		라는 전제로 부터 시작하는 MST
*  해당 문제는 "모든" 컴퓨터를 연결하는 데 필요한 "최소 비용"을 출력하는 문제이므로
*		MST 적용해야 함
*/

struct CHECK {
	int start, end;
	int cost;

	bool operator<(const CHECK&i)const {
		return cost > i.cost; // 비용 오름차순으로 정렬
	}
};
priority_queue<CHECK> tree;
int parent[1001];

int n, m;

int answer;

// MST의 베이스는 유니온 파인드
int treeFind(int a) {
	if (a == parent[a]) return a;

	return parent[a] = treeFind(parent[a]);
}

void treeUnion(int a, int b) {
	int aRoot = treeFind(a);
	int bRoot = treeFind(b);

	parent[aRoot] = bRoot;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		tree.push({ a,b,c });
	}

	for (int i = 1; i <= n; ++i) parent[i] = i;

	int cnt = 0;
	while (!tree.empty()) {
		CHECK now = tree.top();
		tree.pop();

		if (cnt == n - 1) break;

		if (treeFind(now.start) == treeFind(now.end)) continue;

		// 두 정점 연결 X면
		else {
			// 간선 추가 후, 두 정점을 하나의 그룹으로 만든다.
			treeUnion(now.start, now.end);
			answer += now.cost; // 모든 컴터 연결의 최소 비용
			cnt++;
		}
	}

	cout << answer;

	return 0;
}