#include <iostream>
#include <vector>

using namespace std;

bool isEnd = false;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, K;

	cin >> N >> K;
	
	vector<bool> checked(N + 1, false);
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (isEnd) break;

		if (!checked[i]) {
			checked[i] = true;
			//cout << i << " ";
			cnt++;
			if (cnt == K) {
				isEnd = true;
				cout << i << "\n";
				break;
			}

			int num = 2;
			while (i * num <= N) {
				if (!checked[i * num]) {
					checked[i * num] = true;
					//cout << i * num << " ";
					cnt++;
					if (cnt == K) {
						isEnd = true;
						cout << i *num << "\n";
						break;
					}
					if (isEnd) break;
				}
				num++;
			}
		}
	}
	return 0;
}