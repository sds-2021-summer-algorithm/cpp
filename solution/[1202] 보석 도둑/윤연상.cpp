/*
* 탐욕법으로 최적해 구하는 문제
* 우선순위 큐를 활용
* 작은 가방부터 시작해서 가방에 넣을 수 있는 보석을 계속 pq에 넣음
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int bags[300001];
pair<int, int> jewerly[300001];
priority_queue<int> pq;

void _input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v; cin >> m >> v;
		jewerly[i] = make_pair(m, v);
	}
	for (int i = 0; i < k; i++) {
		cin >> bags[i];
	}
	sort(jewerly, jewerly + n);
	sort(bags, bags+k);
}

ll pick_items() {
	ll retval = 0;

	int idx = 0;
	for (int i = 0; i < k;i++) {
		while (idx < n && bags[i] >= jewerly[idx].first) {
			pq.push(jewerly[idx++].second);
		}
		if (!pq.empty()) {
			retval += (ll)pq.top(); 
			pq.pop();
		}
	}
	return retval;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	_input();

	cout << pick_items();

	return 0;
}