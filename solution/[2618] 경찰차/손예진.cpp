#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int N, W;
int dp[1002][1002][2];
vector<pair<int, int>> incidents;

int MovePolice(int idx, int p1, int p2) {	//idx: 사건 번호, p1, p2: 1번, 2번 경찰차 마지막으로 처리한 사건
	if (idx >= W + 2)
		return 0;
	int& ret = dp[p1][p2][0];
	if (ret != -1)
		return ret;
	//abs(현재 각 경찰차의 위치 - 새로 해결해야할 사건의 위치) 구해서 더 작은 것을 return
	//주의할 점: 이후의 사건들도 고려해서 재귀함수 리턴값을 더해서 고려 -> 모든 상황에 대해 고려해서 dp 값 업데이트 하는 것임!
	int p1_dist = abs(incidents[idx].first - incidents[p1].first) + abs(incidents[idx].second - incidents[p1].second) + MovePolice(idx + 1, idx, p2);
	int p2_dist = abs(incidents[idx].first - incidents[p2].first) + abs(incidents[idx].second - incidents[p2].second) + MovePolice(idx + 1, p1, idx);
	
	//현재 위치에서 다음에는 어느 위치로 가는가
	if (p1_dist < p2_dist) {
		dp[p1][p2][1] = 1;
		ret = p1_dist;
	}
	else {
		dp[p1][p2][1] = 2;
		ret = p2_dist;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> W;
	incidents.push_back({ 1, 1 });
	incidents.push_back({ N, N });
	memset(dp, -1, sizeof(dp));
	for (int i = 2; i < W + 2; i++) {
		int r, c;
		cin >> r >> c;
		incidents.push_back({r, c});
	}
	cout << MovePolice(2, 0, 1) << "\n";
	int p1 = 0, p2 = 1;
	for (int i = 2; i < W + 2; i++) {
		if (dp[p1][p2][1] == 1) {
			p1 = i;
			cout << "1\n";
		}
		else {
			p2 = i;
			cout << "2\n";
		}
	}
	
}
