#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int target;
	int weight;

	Edge(int target, int weight) {
		this->target = target;
		this->weight = weight;
	}
};

vector<vector<Edge>> v;
vector<bool> checked;

int answer = 0;

void DFS(int index, int sum, bool isStart) {
	// üũ��
	checked[index] = true;
	// �������ΰ�? (������� �ƴϰ� ���� ����ϰ�쿡 ����)
	if (!isStart && v[index].size() == 1) {
		answer = max(answer, sum);
		checked[index] = false;
		return;
	}

	// ��ȸ�� �� �ִ°�?
	for (int i = 0; i < v[index].size(); i++) {
		Edge next = v[index][i];

		// �湮�� �� �ִ°�?
		// �湮 ���� �ʾ����� �湮�� ���� ����
		if (!checked[next.target]) {
			// �湮
			DFS(next.target, sum + next.weight, false);
		}
	}
	// üũ�ƿ�
	checked[index] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;


	v = vector<vector<Edge>>(N + 1);
	checked = vector<bool>(N + 1, false);
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(Edge(b, c));
		v[b].push_back(Edge(a, c));
	}

	for (int i = 0; i < N; i++) {
		// ���� ��尡 Ʈ���� ���� ����� ��쿡 DFS Ž��
		if (v[i].size() == 1) {
			DFS(i, 0, true);
		}
	}

	cout << answer << "\n";
	return 0;
}