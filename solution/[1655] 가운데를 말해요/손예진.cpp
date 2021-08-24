#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//두 개의 priority_queue -> 하나는 중간 값보다 작은 값 push, 다른 하나는 중간 값 보다 큰 값 push
//작은 값은 내림차순, 큰 값은 오름차순;

struct cmp {
	bool operator()(int& n1, int& n2) {
		return n1 > n2;
	}
};

int N;
priority_queue<int> pq_low; //중간 값보다 작은 값들
priority_queue<int, vector<int>, cmp> pq_high;  //중간 값보다 큰 값들

//time complexity: N * log(N/2) *  log(N/2)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int mid;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		if (i == 1)
			mid = n;
		else {
			if (n <= mid)
				pq_low.push(n);
			else
				pq_high.push(n);

			if (i % 2 == 0) { //짝
				if (pq_low.size() == i / 2) {
					int tmp = pq_low.top();
					pq_low.pop();
					pq_high.push(mid);
					mid = tmp;
				}
			}
			else {	//홀
				if (pq_high.size() == (i + 1) / 2) {
					int tmp = pq_high.top();
					pq_high.pop();
					pq_low.push(mid);
					mid = tmp;
				}
			}
		}
		cout << mid << "\n";
	}
}
