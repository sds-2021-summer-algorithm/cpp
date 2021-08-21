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
	// 입력을 받는 개수는 M개 
	// 도시를 입력받고 처음 입력을 받는다면 root를 얻어서
	// root와 이후 받은 도시와 비교를 한다.
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