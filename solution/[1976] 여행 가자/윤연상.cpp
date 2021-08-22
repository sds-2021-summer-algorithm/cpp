/*
* 단순히 도시를 여행할 수 있는 지에 대한 여부만 확인하는 문제
* 도시간 여행 여부를 확인만 하면 되기 때문에
* => Union Find를 사용함
* 
* 1. 주어진 인접행렬을 이용하여 모든 간선들에 대해 merge를 수행
* 2. 트리가 다 만들어지면 여행 가고자 하는 도시들이 같은 집합에 속해있는지 확인
* 
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m;
struct DisJointSet {	// 서로소 집합
	int parent[201];

	void init(int n) {
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}
	int find(int n) {
		if (parent[n] == n) return n;
		return parent[n] = find(parent[n]);	// 경로 압축
	}
	void merge(int n1, int n2) {
		n1 = find(n1); 
		n2 = find(n2);
		
		if (n1 != n2) parent[n1] = n2;
	}
};
DisJointSet djs;

bool solve() {
	cin >> n >> m;

	djs.init(n);	// 서로소 집합 초기화

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a; cin >> a;
			if (a == 1)
				djs.merge(i, j);	// 간선 존재하면 merge 수행
		}
	}

	int first; cin >> first;
	first = djs.find(first);		

	for (int i = 0; i < m - 1; i++) {
		int city; cin >> city;
		if (first != djs.find(city))	
			return false;
	}

	return true;
}


int main(void) {
	fastio;

	if (solve())
		cout << "YES";
	else
		cout << "NO";
}