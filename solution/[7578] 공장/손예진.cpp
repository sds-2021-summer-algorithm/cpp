#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* <idea>
* 나보다 먼저 방문한 나보다 큰 값의 개수의 합.
* 1. B 배열 기준으로 각 부품의 순서 지정 -> A배열의 동일한 부품 번호에도 해당 순서 적용
* 2. indexed tree 구간 합 활용하여 visited의 개수 확인 - A배열의 첫 번째 부품부터 순회
* 3. 개수 확인 후 해당 부품 방문했음을 알리기 위해 indexed tree 구간 합 갱신
* 4. 3에서 확인한 개수의 합 출력
* 
* <주의할 점>
* 1. indexed tree 루트는 index 1임. 0 아님.
* 2. 리프 노드는 S - 1 + i부터 시작 (i >= 1) => 즉 (S ~ S + N - 1)
*/

int S = 1, N, A[1000001], tmp[1000001];
vector<long long> tree;

void update(int left, int right, int node, int target, int diff) {
	if (right < target || left > target)
		return;
	tree[node] += diff;
	if (left == right)
		return;
	update(left, (left + right) / 2, node * 2, target, diff);
	update((left + right) / 2 + 1, right, node * 2 + 1, target, diff);
}

long long query(int left, int right, int node, int ql, int qr) {
	if (right < ql || left > qr)
		return 0;
	if (ql <= left && right <= qr)
		return tree[node];
	return query(left, (left + right) / 2, node * 2, ql, qr) 
		+ query((left + right) / 2 + 1, right, node * 2 + 1,ql, qr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (S < N) {
		S *= 2;
	}
	tree.resize(S * 2);
	for (int i = 1; i <= N; i++) {	//A 배열 입력 받기
		int t;
		cin >> t;
		tmp[t] = i;	//A배열 기계의 번호 => 원래 순서와 매칭할 수 있게
	}
	for (int i = 1; i <= N; i++) {	//B 배열 입력 받기
		int t;
		cin >> t;
		A[tmp[t]] = i;	//A배열 초기화
	}
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += query(1, N, 1, A[i] + 1, N);
		update(1, N, 1, A[i], 1);
	}
	cout << ans << "\n";
}
