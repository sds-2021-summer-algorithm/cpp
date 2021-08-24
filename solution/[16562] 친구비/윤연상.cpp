/**********************************************************************
작성일 : 2021-08-24
작성자 : 윤연상
문제 :
	모든 사람을 자신의 친구로 만들기 위한 최소비용을 구하는 문제
		1. 각 사람은 친구가 되기 위한 친구비 A(i)가 존재
		2. 친구의 친구는 굳이 돈을 안내도 친구로 만들 수 있음
		3. 1~N까지의 사람들의 친구관계를 m번의 친구관계를 통해 나타냄
풀이 :
	각 친구관계를 Union Find로 나타냄
	친구관계를 나타내는 서로소 집합 내에서 최소 친구비를 가지는 사람만을 뽑음
		1. 트리내에서 최소 친구비를 바로 찾기 위해 Union by payment를 이용
		2. Union by payment는 두 트리를 Union시 각 루트의 친구비를 비교해 작은 트리에 큰 트리를 넣음
		3. Union by payment를 사용시 트리 내 최소 비용은 항상 루트에 위치함
		4. 따라서 총 비용 계산시 각 트리의 루트만을 사용
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : O(mlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m, k;

struct DisJointSet {
	int parent[10001];	// 각 노드의 부모
	int payment[10001];	// 각 노드의 친구비
	bool isRoot[10001];	// 해당 노드가 root인지에 대한 여부

	void init(int n) {	// init 
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			isRoot[i] = true;
			cin >> payment[i];
		}
	}
	int find(int n) {
		if (parent[n] == n) return n;
		return parent[n] = find(parent[n]);
	}
	void merge(int a, int b) {
		int pa = find(a);
		int pb = find(b);

		if (pa == pb) 
			return;
		else if (payment[pa] > payment[pb]) // 두 트리의 루트인 pa와 pb의 payment를 비교
			swap(pa, pb);	

		parent[pb] = pa;
		isRoot[pb] = false;
	}
	int get_min_payment() {		// 루트들만 뽑아서 총 비용에 합산
		int retval = 0;
		for (int i = 1; i <= n; i++) {
			if (isRoot[i])
				retval += payment[i];
		}
		return retval;
	}
};
DisJointSet dsu;

int main(void) {
	fastio;

	cin >> n >> m >> k;

	dsu.init(n);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		dsu.merge(a, b);
	}

	int ans = dsu.get_min_payment();

	if (ans > k)
		cout << "Oh no";
	else
		cout << ans;

}