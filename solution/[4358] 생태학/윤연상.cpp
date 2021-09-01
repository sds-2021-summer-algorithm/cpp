/**********************************************************************
작성일 : 2021-09-01
작성자 : 윤연상
문제 :
	나무 한 그루씩 입력을 받고 
	각 나무 종류가 전체에서 몇 퍼센트 차지하는 지를 구하는 문제
풀이 :
	단순히 Key, Value 자료구조를 이용해서 각 나무의 수를 저장
	map 자료구조를 활용함
	함정 => 입력의 개수가 미리 주어지지 않아 while문을 통해 구현
	소수점 제한 문법 활용
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nlogn) (map에서 access하는 데 걸리는 시간 logn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int cnt = 0;
map<string, int> trees;

int main(void) {
	fastio;

	string str;
	while (getline(cin, str)) {
		trees[str]++;
		cnt++;
	}
	
	cout<<fixed;
	cout.precision(4);

	map<string, int>::iterator iter;
	for (iter = trees.begin(); iter != trees.end(); iter++) {
		double percent = 100.0 * (double)iter->second / (double)cnt;
		cout << iter->first << ' ' << percent << '\n';
	}
}