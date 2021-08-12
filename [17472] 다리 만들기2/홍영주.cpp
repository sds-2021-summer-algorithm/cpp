/*https://seokeeee.tistory.com/83
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numbering = 0;
int N, M;
int mx[4] = { 0,0,1,-1 };
int my[4] = { 1,-1,0,0 };
vector<vector<int>> m;
vector<int> parent;
struct Edge {
	int start;
	int end;
	int cost;

	Edge(int start, int end, int cost) {
		this->start = start;
		this->end = end;
		this->cost = cost;
	}
};

struct compare {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

priority_queue<Edge, vector<Edge>, compare> pq;

bool isPossible(int y, int x) {
	return 0 <= x && x < M && 0 <= y && y < N;
}

void DFS(int y, int x, int n) {
	// üũ��
	m[y][x] = n;
	

	// ��ȸ�� �� �ִ°�?
	for (int i = 0; i < 4; i++) {
		int ty = my[i] + y;
		int tx = mx[i] + x;

		// �湮�� �� �ִ°�?
		if (isPossible(ty, tx) && m[ty][tx] == -1) {

			// �湮
			DFS(ty, tx ,n);
		}
	}
}

bool CanIMakeBridge(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ty = y + my[i];
		int tx = x + mx[i];

		if (isPossible(ty, tx) && m[ty][tx] == 0) {
			return true;
		}
	}
	return false;
}

void make_bridge(int y, int x, int value) {
	for (int i = 0; i < 4; i++) {
		int ty = y;
		int tx = x;
		int length = 0;

		while (1)
		{
			ty += my[i];
			tx += mx[i];

			if (!isPossible(ty, tx) || m[ty][tx] == value) break;
			if (m[ty][tx] == 0) {
				length++;
				continue;
			}

			if (m[ty][tx] != value) {

				if (length > 1) {
					pq.push(Edge(value, m[ty][tx], length));
					break;
				}


				break;
			}

		}
	}
}

int Find(int i) {
	if (parent[i] == i) return i;
	else {
		return parent[i] = Find(parent[i]);
	}
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa < pb) parent[pb] = pa;
	else parent[pa] = pb;
}

int main() {

	cin >> N >> M;
	m = vector<vector<int>>(N, vector<int>(M, 0));

	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;

			if (a == 1) {
				a = -1;
			}
			m[i][j] = a;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == -1) {
				numbering++;
				DFS(i, j, numbering);
			}
		}
	}

	/*
	if (numbering == 0) {
		cout << -1 << "\n";
		return 0;
	}
	*/

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (CanIMakeBridge(i, j)) {
				make_bridge(i, j, m[i][j]);
			}
		}
	}

	// ���� �迭 �ʱ�ȭ
	parent = vector<int>(numbering + 1);

	for (int i = 1; i <= numbering; i++) {
		parent[i] = i;
	}

	/*
	cout << "\n\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}

	*/
	// MST �˰���
	int sum = 0;
	int cnt = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		//cout << now.start << " " << now.end << " " << now.cost << "\n";

		// MST �����. MST�� ������ ���ǰ��� - 1���̴�.
		if (cnt == numbering - 1) break;

		// �� ���� ����Ǿ����� �ʴٸ�
		if (Find(now.start) != Find(now.end)) {
			Union(now.start, now.end);
			cnt++;
			sum += now.cost;
		}

	}

	// parent�� ������ �� �Ǿ����� �ȵǾ����� �Ǵ��� �Ѵ�.
	// ��� ���� ���� ������ �Ǿ��־���ϹǷ� parent[1]�� �ϳ��� �ٸ��� ������ �ȵǾ�����!!
	int check_num = Find(1);
	for (int i = 2; i <= numbering; i++) {
		if (check_num != Find(i)) {
			sum = -1;
		}
	}
	cout << sum << "\n";

	return 0;
}