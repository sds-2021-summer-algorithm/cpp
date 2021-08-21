#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

	string S, T;

	cin >> S >> T;


	while (S.length() != T.length()) {
		if (T.back() == 'A') {
			T.pop_back();
		}
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}

	cout << (S == T) << "\n";
	return 0;
}