#include <iostream>

using namespace std;

int N, M, nums[1025][1025], accum[1025][1025], dist[1025][1025];

void update(int y, int x, int diff) {
	for (int j = x; j <= N; j++) {
		accum[y][j] += diff;
	}
	nums[y][x] += diff;
}

int query(int y1, int x1, int y2, int x2) {
	int ans = 0;
	for (int i = y1; i <= y2; i++) {
		ans += accum[i][x2] - accum[i][x1 - 1];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		int sum = 0;
		for (int j = 0; j <= N; j++) {	//각 행에 대한 누적합
			if (i != 0 && j != 0) {
				cin >> nums[i][j];
				sum += nums[i][j];
			}
			accum[i][j] = sum;
		}
	}
	for (int i = 0; i < M; i++) {
		int w;
		cin >> w;
		if (w == 0) {	//값 변환 연산
			int x, y, c;
			cin >> y >> x >> c;
			update(y, x, c - nums[y][x]);	//update를 하기 위해 매번 nums를 참조하기 때문에 update 이후에 nums 값 갱신 필요
		}
		else {	//누적합 연산
			int x1, y1, x2, y2;
			cin >> y1 >> x1 >> y2 >> x2;
			cout << query(y1, x1, y2, x2) << "\n";
		}
	}
}
