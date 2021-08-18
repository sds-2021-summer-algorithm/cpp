/*
* 문제 설명이 너무 빈약해서 살짝 헤맸음
* 계속 사탕을 넣었다 뺐다가 반복 연산을 해야함 => 세그멘트 트리?
* 사탕 맛 종류가 1~1000000까지 있음 
* => 각 맛 별 사탕을 저장하고 순위를 계산해야함
* => 순위 계산은 가지치기를 통해 rank에 맞는 leaf node로 찾아감
*/
#include <bits/stdc++.h>
#define S 1048576

using namespace std;

int n;
int idxTree[2 * S + 1];

void update(int node, int diff) {
	// Bottom up 방식으로 노드 갱신
	while (node >= 1) {
		idxTree[node] += diff;
		node /= 2;
	}
}

int findCandy(int node, int rank) {
	// Top Down 방식으로 rank의 맞는 사탕 맛을 찾아감
	if (node >= S) {
		return node - S + 1;
	}

	int left = idxTree[node * 2];
	int right = idxTree[node * 2 + 1];

	if (left >= rank) {
		return findCandy(node * 2, rank);
	}
	else {
		return findCandy(node * 2 + 1, rank - left);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int op; cin >> op;
		if (op == 1) {
			int rank; cin >> rank;
			int favor = findCandy(1, rank);
			update(favor + S - 1, -1);	// 순위의 맞는 사탕을 찾고 개수를 빼줌
			cout << favor << '\n';
		}
		else if (op == 2) {
			int idx, diff; cin >> idx >> diff;
			int node = idx + S - 1;
			update(node, diff);
		}
	}
}