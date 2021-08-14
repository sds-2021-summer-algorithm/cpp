#include <iostream>
#include <algorithm>

using namespace std;

//K번째 수는 최대 K임. 따라서 답은 1 ~ K 중에 있음
//이 전제를 바탕으로 이분탐색 수행
//매 mid에 대해서 1 ~ N의 for문을 돌리며 각 열에 있는 mid보다 작거나 같은 수의 개수 count

int N, K;

int main() {
	cin >> N >> K;

	int left = 1, right = K, ans = K;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 1; i <= N; i++) {	//각 i에 대해 'i * j <= mid'인 j의 개수 구하기
			cnt += min(mid / i, N);	//각 열에서 가능한 j의 최대 개수는 N개
		}
		if (cnt >= K) {
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans << "\n";

}
