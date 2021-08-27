#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string total;
	string sub;

	getline(cin, total);
	getline(cin, sub);

	int i = 0;
	int cnt = 0;
	while (true) {
		int index = total.find(sub, i);
		if (index == -1) {
			break;
		}
		else {
			cnt++;
			i = index + sub.size();
			//cout << i << "\n";
		}
	}
	cout << cnt << "\n";
	return 0;
}