/*
* 아이디어 도출 과정
* 우선 구간합을 구해야하기 때문에 DP or 인덱스 트리 고려
* 값이 중간에 계속 바뀜 => 인덱스 트리
* Bottom - up으로 구현
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int S = 1;
int n, m, k;
ll idxTree[2097153];

void makeS(int n) {
	// 수의 개수 n을 통해 S를 구함
	while (S < n) {
		S *= 2;
	}
}
void _input() {
	// input 함수
	cin >> n >> m >> k;
	makeS(n);

	for (int i = S; i < S + n; i++) {
		cin >> idxTree[i];
	}
}
void initBU() {
	// 트리 초기화 함수(Bottom - up) 
	for (int i = S - 1; i > 0; i--) {
		idxTree[i] = idxTree[i * 2] + idxTree[i * 2 + 1];
	}
}
void updateBU(int idx, ll num) {
	// 수 갱신을 위한 함수 (Bottom - up)
	idx = idx + S - 1;
	ll diff = num - idxTree[idx];

	while (idx >= 1) {
		idxTree[idx] += diff;
		idx /= 2;
	}
}
ll queryBU(int left, int right) {
	// query 수행 함수 (Bottom - up)
	ll retval = 0;

	left = left + S - 1;
	right = right + S - 1;

	while (left <= right) {
		if (left % 2) {
			retval += idxTree[left];
			left = (left + 1) / 2;
		}
		else {
			left /= 2;
		}
		if (right % 2) {
			right /= 2;
		}
		else {
			retval += idxTree[right];
			right = (right - 1) / 2;
		}
	}
	return retval;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	_input();
	initBU();

	for (int i = 0; i < m + k; i++) {
		ll op, a, b;
		cin >> op >> a >> b;
		if (op == 1) {
			updateBU(a, b);
		}
		else if (op == 2) {
			cout << queryBU(a, b) << '\n';
		}
	}
}