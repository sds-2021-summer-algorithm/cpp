#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;


int Find(int i) {
	if (parent[i] == i) return i;
	else {
		return parent[i] = Find(parent[i]);
	}
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	// 작은것을 향하게끔 설정
	
	if (pb > pa) {
		parent[pb] = pa;
	}
	else {
		parent[pa] = pb;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M;

	cin >> N >> M;

	parent = vector<int>(N + 1);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	int known_number;
	cin >> known_number;

	// 진실을 아는 사람들은 0을 루트로 향하게끔 만든다.
	for (int i = 0; i < known_number; i++) {
		int a;
		cin >> a;
		parent[a] = 0;
	}

	vector<int> parties;
	for (int i = 0; i < M; i++) {
		int party_number;
		cin >> party_number;

		int first_number;
		for (int j = 0; j < party_number; j++) {
			int a;
			cin >> a;
			// 각 파티의 대표
			if (j == 0) {
				first_number =a;
				parties.push_back(a);
			}
			else {
				// 각 파티의 대표와 현재 사람과 Union
				Union(first_number, a);
			}
		}
	}

	// 각 파티의 대표 인덱스인 사람이 진실을 알고 있지 않다면 cnt++ 증가!
	int cnt = 0;
	for (int i = 0; i < parties.size(); i++) {
		if (Find(parties[i]) != 0) cnt++;
	}
	cout << cnt << "\n";

}