#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 201

using namespace std;

int N, K, bulb[201], dp[201][201];	//dp[i][j]: bulb[i]의 색깔로 i ~ j의 전구 색상을 통일시키기 위해 필요한 최소 변경 횟수

int SetColor(int start, int end) {
	//자기자신 - 색상 변경할 필요 없음
	if (start == end)
		return 0;
	//이미 아는 값
	if (dp[start][end] > 0)
		return dp[start][end];

	//해당 범위의 모든 경우에 대해 최솟값을 찾은 뒤 마지막에 dp값 갱신
	int tmp = MAX;
	for (int i = start; i < end; i++) {
		int left = SetColor(start, i);
		int right = SetColor(i + 1, end);
		if (bulb[start] != bulb[i + 1])
			tmp = min(tmp, left + right + 1);
		else
			tmp = min(tmp, left + right);
	}
	return dp[start][end] = tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> bulb[i];
	}
	cout << SetColor(0, N - 1) << "\n";
}
