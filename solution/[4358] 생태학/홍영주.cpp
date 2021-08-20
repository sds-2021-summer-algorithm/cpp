#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;

	map<string, int> m;
	int cnt = 0;


	// getline을 while을 통해서 받는다면 
	// EOF(Ctrl + Z)가 나올 때까지  입력을 받는다.
	while(getline(cin, str)) {
		cnt++;
		if (m.find(str) == m.end()) {
			m.insert(make_pair(str, 1));
		}
		else {
			m[str]++;
		}
	}

	cout << fixed;
	cout.precision(4);

	// 맵에서 입력을 받을 때 맵은 순서가 있기 때문에, 자동으로 키값을 기준으로 정렬하는 것을 알 수가 있다.
	for (auto a : m) {
		cout << a.first << " " << ((double)a.second * 100 ) / cnt << "\n";
	}

	return 0;
}