#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M;
long long N, rides[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	long long t = 0; 
	bool fin = false;
	for (int i = 1; i <= M; i++) {
		cin >> rides[i];
	}
	//(학생 수 <= 놀이기구 수) -> N번째 놀이기구 탑승 가능
	if (N <= M) {
		cout << N << "\n";
		return 0;
	}
		
	long long left = 0, right = 30 * N;	//필요한 최대 시간: 배차간격이 30분인 놀이기구 한 대만 운영중일 때
	while (left <= right) {
		long long cnt = 0;
		long long mid = (left + right) / 2;
		//mid분 전까지 놀이기구를 탄 학생 수 구하기
		for (int i = 1; i <= M; i++) {	//모든 경우에 대해 놀이기구 탑승 가능 순서 알 필요 없음. 해당되는 시간에만 차례 알면 됨
			cnt += (mid - 1) / rides[i] + 1;
		}
		for (int i = 1; i <= M; i++) {
			if (!(mid % rides[i])) {
				if (++cnt == N) {
					cout << i << "\n";
					return 0;
				}
			}
		}
		if (cnt < N) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
}
