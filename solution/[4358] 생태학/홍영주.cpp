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


	// getline�� while�� ���ؼ� �޴´ٸ� 
	// EOF(Ctrl + Z)�� ���� ������  �Է��� �޴´�.
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

	// �ʿ��� �Է��� ���� �� ���� ������ �ֱ� ������, �ڵ����� Ű���� �������� �����ϴ� ���� �� ���� �ִ�.
	for (auto a : m) {
		cout << a.first << " " << ((double)a.second * 100 ) / cnt << "\n";
	}

	return 0;
}