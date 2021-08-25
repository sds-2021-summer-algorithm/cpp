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
	// 기하학적으로 2R >= 두점사이의 거리 이면 만나는 것을 의미한다.
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
			// 예전에 입력받은 벡터 값들과 비교한다.
			for (int j = 0; j < v.size(); j++) {
				// 만약 이미 같은 그룹에 속하여있다면 패스
				if (Find(i) == Find(j)) continue;

				//만약 둘이 서로 만난다면 같은 그룹으로 묶기
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