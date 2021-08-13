#include <bits/stdc++.h>
#define SIZE 100001

using namespace std;
typedef long long ll;

int n, m;
int arr[SIZE];

// 이분 탐색 
int find(int num) {
	int retval = 0;
	int left = 0;
	int right = n - 1;

	while (1) {
		if (left > right)
			break;

		int mid = (left + right) / 2;

		if (arr[mid] > num) {
			right = mid - 1;
		}
		else if (arr[mid] < num) {
			left = mid + 1;
		}
		else {
			retval = 1;
			break;
		}
	}
	return retval;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);	// 이분탐색을 위한 정렬

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		cout << find(num) << '\n';
	}
}