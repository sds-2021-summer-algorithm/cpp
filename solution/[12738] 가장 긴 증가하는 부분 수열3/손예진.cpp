#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> order;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		auto iter = lower_bound(order.begin(), order.end(), n) - order.begin();
		if (iter == order.size())
			order.push_back(n);
		else
			order[iter] = n;
	}
	cout << order.size() << "\n";
}
