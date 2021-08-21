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

	parent[pb] = pa;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;

	cin >> N >> M;

	vector<vector<int>> input(N + 1, vector<int>(N + 1));
	parent = vector<int>(N + 1);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			if (input[i][j] == 1) {
				Union(i, j);
			}
		}
	}


	
	int isOkay = true;
	int root;
	// �Է��� �޴� ������ M�� 
	// ���ø� �Է¹ް� ó�� �Է��� �޴´ٸ� root�� ��
	// root�� ���� ���� ���ÿ� �񱳸� �Ѵ�.
	for (int i = 0; i < M; i++) {
		int city;
		cin >> city;

		if (i == 0) {
			root = Find(city);
		}
		else {
			if (root != Find(city)) {
				isOkay = false;
				break;
			}
		}
	}


	if (isOkay) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}