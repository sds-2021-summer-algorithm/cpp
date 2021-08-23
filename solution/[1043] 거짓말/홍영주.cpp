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
	// �������� ���ϰԲ� ����
	
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

	// ������ �ƴ� ������� 0�� ��Ʈ�� ���ϰԲ� �����.
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
			// �� ��Ƽ�� ��ǥ
			if (j == 0) {
				first_number =a;
				parties.push_back(a);
			}
			else {
				// �� ��Ƽ�� ��ǥ�� ���� ����� Union
				Union(first_number, a);
			}
		}
	}

	// �� ��Ƽ�� ��ǥ �ε����� ����� ������ �˰� ���� �ʴٸ� cnt++ ����!
	int cnt = 0;
	for (int i = 0; i < parties.size(); i++) {
		if (Find(parties[i]) != 0) cnt++;
	}
	cout << cnt << "\n";

}