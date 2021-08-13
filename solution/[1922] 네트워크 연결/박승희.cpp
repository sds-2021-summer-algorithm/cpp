#include <iostream>
#include <queue>
using namespace std;

// Ǯ�� ��¥ : 2021 08 11
// ü�� ���̵� : ������(���� : MST ���� �ؾ����..��)
// ���� ��ȣ : https://www.acmicpc.net/problem/1922

/* "N���� ��带 �����ϴ� �ּ� ����� N-1���� �������� ������ �� �̷�����" 
		��� ������ ���� �����ϴ� MST
*  �ش� ������ "���" ��ǻ�͸� �����ϴ� �� �ʿ��� "�ּ� ���"�� ����ϴ� �����̹Ƿ�
*		MST �����ؾ� ��
*/

struct CHECK {
	int start, end;
	int cost;

	bool operator<(const CHECK&i)const {
		return cost > i.cost; // ��� ������������ ����
	}
};
priority_queue<CHECK> tree;
int parent[1001];

int n, m;

int answer;

// MST�� ���̽��� ���Ͽ� ���ε�
int treeFind(int a) {
	if (a == parent[a]) return a;

	return parent[a] = treeFind(parent[a]);
}

void treeUnion(int a, int b) {
	int aRoot = treeFind(a);
	int bRoot = treeFind(b);

	parent[aRoot] = bRoot;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		tree.push({ a,b,c });
	}

	for (int i = 1; i <= n; ++i) parent[i] = i;

	int cnt = 0;
	while (!tree.empty()) {
		CHECK now = tree.top();
		tree.pop();

		if (cnt == n - 1) break;

		if (treeFind(now.start) == treeFind(now.end)) continue;

		// �� ���� ���� X��
		else {
			// ���� �߰� ��, �� ������ �ϳ��� �׷����� �����.
			treeUnion(now.start, now.end);
			answer += now.cost; // ��� ���� ������ �ּ� ���
			cnt++;
		}
	}

	cout << answer;

	return 0;
}