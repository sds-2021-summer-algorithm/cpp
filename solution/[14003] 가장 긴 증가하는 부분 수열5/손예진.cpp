#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N, index[1000001];	//index: nums의 i번째 값이 가지는 index값
vector<int> nums, index_list;
//index_list: lower_bound를 찾기 위해 생성.
//0 ~ index_list.size() - 1의 index를 가지는, 가장 최근에 갱신된 수들로 구성됨

void LIS() {
	for (int i = 0; i < N; i++) {
		//현재 값보다 큰 수 중 가장 작은 수의 위치 반환
		auto iter = lower_bound(index_list.begin(), index_list.end(), nums[i]) - index_list.begin();  
		index[i] = iter;
		if (iter == index_list.size())	//현재 값이 가장 큰 수라면 vector에 추가하기
			index_list.push_back(nums[i]);
		else //값이 존재한다면 대체하기
			index_list[iter] = nums[i];
	}
}

//가장 끝에 있는 수부터 index 내림차순으로 답이 되는 수열 찾기
stack<int> GetSeq() {	
	int idx = index_list.size() - 1;
	stack<int> ans;
	for (int i = N - 1; i >= 0; i--) {
		if (index[i] == idx) {
			idx--;
			ans.push(nums[i]);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		nums.push_back(n);
	}
	LIS();
	cout << index_list.size() << "\n";
	stack<int> ans = GetSeq();
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
}
