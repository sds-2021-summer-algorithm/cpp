#include <iostream>
#include <queue>
#include <cmath>

#define MAX 2147483647
#define MIN -2147483648
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int, vector<int>, less<int>> pq_less;		// �ִ���
	priority_queue<int, vector<int>, greater<int>> pq_greater;		// �ּ���

	int N; 
	cin >> N;
	pq_less.push(MIN); 
	pq_greater.push(MAX);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		
		// �ִ��� top ���� ���ڰ� ũ�ٸ� �ּ����� a�� �ִ´�.
		if (pq_less.top() < a) {
			pq_greater.push(a);
		}
		else { //
			pq_less.push(a);
		}

		// 1 , 2 
		if (pq_less.size() < pq_greater.size() ) {
			int num = pq_greater.top();
			pq_greater.pop();
			pq_less.push(num);
		}//4 2 
		else if(pq_less.size() > pq_greater.size() + 1){
			int num = pq_less.top();
			pq_less.pop();
			pq_greater.push(num);
		}

		cout << pq_less.top() << "\n";
	}


	return 0;
}