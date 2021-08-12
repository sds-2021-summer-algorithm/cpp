#include<iostream>
#include<vector>
#include <algorithm>
#define MAX 1000000

using namespace std;

//메모리 제한이 4MB이기 때문에 배열을 '이전 dp', '현재 dp'로만 구성해야됨

int N, nums[3], dp_min[2][3], dp_max[2][3];

void PlayGame() {
	//0 <- 0, 1 / 1 <- 0, 1, 2 / 2 <- 1, 2
	//현재 dp를 구하기 위해서는 각각 가능한 이전 dp 중 최솟값 / 최댓값을 구해서 현재 값에 더해주면 됨
	int min0, min1, min2, max0, max1, max2;
	min0 = min(dp_min[0][0], dp_min[0][1]);
	max0 = max(dp_max[0][0], dp_max[0][1]);
	min1 = min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]);
	max1 = max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]);
	min2 = min(dp_min[0][1], dp_min[0][2]);
	max2 = max(dp_max[0][1], dp_max[0][2]);
			
	dp_min[1][0] = nums[0] + min0;
	dp_max[1][0] = nums[0] + max0;
	dp_min[1][1] = nums[1] + min1;
	dp_max[1][1] = nums[1] + max1;
	dp_min[1][2] = nums[2] + min2;
	dp_max[1][2] = nums[2] + max2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> nums[0] >> nums[1] >> nums[2];
		PlayGame();
		//다음줄로 넘어가기 전에 '현재 dp'를 '이전 dp' 위치로 옮겨주기
		for (int j = 0; j < 3; j++) {
			dp_min[0][j] = dp_min[1][j];
			dp_max[0][j] = dp_max[1][j];
		}
	}

	//마지막에 저장된 '현재 dp' 중 최댓값 / 최솟값 구하기 
	int ans_max = 0, ans_min = MAX;
	for (int i = 0; i < 3; i++) {
		ans_max = (dp_max[1][i] > ans_max ? dp_max[1][i] : ans_max);
		ans_min = (dp_min[1][i] < ans_min ? dp_min[1][i] : ans_min);
	}
	cout << ans_max << " " << ans_min << "\n";
}
