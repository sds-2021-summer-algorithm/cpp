#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, loc[40001], index[40001];
vector<int> order;

void LIS() {
	for (int i = 0; i < N; i++) {
		auto iter = lower_bound(order.begin(), order.end(), loc[i]) - order.begin();
		if (iter == order.size())
			order.push_back(loc[i]);
		else
			order[iter] = loc[i];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> loc[i];
	}
	LIS();
	cout << order.size() << "\n";
}
