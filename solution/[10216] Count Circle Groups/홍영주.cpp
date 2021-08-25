#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> parent;
struct Point {
	int id;
	int x;
	int y;
	int r;

	Point(int id, int x, int y, int r) {
		this->id = id;
		this->x = x;
		this->y = y;
		this->r = r;
	}
	// ������������ 2R >= ���������� �Ÿ� �̸� ������ ���� �ǹ��Ѵ�.
	bool isMeetingTo(Point p) {
		double distance = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
		return ((r + p.r) >= distance) ? true : false;
	}
};


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
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		parent = vector<int>(N);
		vector<Point> v;
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < N; i++) {
			int x, y, R;

			cin >> x >> y >> R;

			Point now = Point(i, x, y, R);
			// ������ �Է¹��� ���� ����� ���Ѵ�.
			for (int j = 0; j < v.size(); j++) {
				// ���� �̹� ���� �׷쿡 ���Ͽ��ִٸ� �н�
				if (Find(i) == Find(j)) continue;

				//���� ���� ���� �����ٸ� ���� �׷����� ����
				if (now.isMeetingTo(v[j])) {
					Union(i, j);
				}
			}
			v.push_back(now);
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (parent[i] == i) {
				cnt++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}