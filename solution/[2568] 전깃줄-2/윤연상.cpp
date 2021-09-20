/**********************************************************************
작성일 : 2021-09-21
작성자 : 윤연상
문제 :
	전깃줄이 서로 교차하지 않도록 현재 연결된 전깃줄을 제거함
	제거해야하는 전깃줄이 최소가 되도록 해야하고 제거하는 전깃줄을 다 구해야함
	=> 경우의 수 여러가지 생기지만, 그 중 하나만 출력
	전깃줄 개수 <= 100000, 전깃줄 구멍 <= 500000
풀이 :
	빈 전깃줄 구멍을 처리하기 위해 배열에 -1을 넣어 식별 가능하도록 함
	연결된 전깃줄에서 교차하지 않는 최대 개수를 구함(LIS 수행)
		=> 제거해야하는 최소 전깃줄 구하는 것과 동일
	index 배열에서 seq를 stack에 넣는 것 대신 -1로 바꿔줌
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;	// 전기줄 개수
int lines[500001];	
int Index[500001];
vector<int> idx_list;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int idx; cin >> idx;
		cin >> lines[idx];
	}
}
void LIS() {
	for (int i = 1; i <= 500000; i++) {
		if (lines[i] != -1) {	// 빈 구멍이면 그냥 넘어감
			int iter = lower_bound(idx_list.begin(), idx_list.end(), lines[i]) - idx_list.begin();

			if (iter < idx_list.size()) {
				idx_list[iter] = lines[i];
			}
			else {
				idx_list.push_back(lines[i]);
			}
			Index[i] = iter;
		}
	}
}
void mark_seq() {
	int idx = (int)idx_list.size() - 1;
	for (int i = 500000; i >= 0; i--) {
		if (lines[i] != -1 && Index[i] == idx) {
			idx--;
			Index[i] = -1;	// 선택된 i를 지우기(빈 구멍으로 만들기)
		}
	}
}
int main(void) {
	fastio;

	fill(lines, lines + 500001, -1);	// 초기화
	fill(Index, Index + 500001, -1);

	input();	// 입력
	LIS();		// LIS 수행 및 index 배열 수행
	mark_seq();	// LIS에 포함되는 항을 지우기 => 선택 안된 것을 가려냄

	cout << n - (int)idx_list.size() << '\n';	// 비어있지 않는 구멍만 출력(= 선택되지 않음)
	for (int i = 1; i <= 500000; i++) {
		if (lines[i] != -1 && Index[i] != -1) {
			cout << i << '\n';
		}
	}

	return 0;
}