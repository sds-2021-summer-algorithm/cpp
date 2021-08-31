#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M;

	cin >> N >> M;

	int init = min(N, M) - 1;

	vector<vector<int>> m(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			m[i][j] = str[j] - '0';
		}
	}

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}*/


	int anw = 1;
	bool isFind = false;
	for (int k = init; k >= 1; k--) {
		if (isFind) break;
		for (int i = 0; i < N - k; i++) {
			if (isFind) break;
			for (int j = 0; j < M- k; j++) {
				int temp = m[i][j];

				if (temp == m[i + k][j] && temp == m[i][j + k] && temp == m[i + k][j + k]) {
					anw = (k + 1) * (k + 1);
					isFind = true;
					break;
				}
			}
		}
	}

	cout << anw << "\n";

	return 0;
}