/**********************************************************************
작성일 : 2021-09-20
작성자 : 윤연상
문제 :
	연결선이 서로 꼬이지 않도록 하는 최대 연결 개수
풀이 :
	=> 연결선이 꼬인다 == 연결된 port 수가 감소한다.
	=> 감소하지 않도록 선택 => 최장 증가 부분 수열(LIS)
	STL의 lower_bound를 직접 구현해보았다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
int ports[40001];
vector<int> index_list;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ports[i];
	}
}

int get_index(int num) {	// 이분탐색
	int left = 0;
	int right = (int)index_list.size();

	while (left < right) {
		int mid = (left + right) / 2;

		if (index_list[mid] < num)
			left = mid + 1;
		else if (index_list[mid] > num)
			right = mid;
		else
			return mid;
	}
	return left;
}

int LIS() {
	for (int i = 1; i <= n; i++) {
		//int iter = lower_bound(index_list.begin(), index_list.end(), ports[i]) - index_list.begin();
		int iter = get_index(ports[i]);

		if (iter < (int)index_list.size()) {
			index_list[iter] = ports[i];
		}
		else {
			index_list.push_back(ports[i]);
		}
	}

	return (int)index_list.size();
}

int main(void) {
	fastio;

	input();
	cout << LIS();
	
	return 0;
}