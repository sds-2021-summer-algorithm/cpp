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
	// 체크인
	checked[index] = true;
	// 목적지인가? (출발점이 아니고 말단 노드일경우에 종료)
	if (!isStart && v[index].size() == 1) {
		answer = max(answer, sum);
		checked[index] = false;
		return;
	}

	// 순회할 수 있는가?
	for (int i = 0; i < v[index].size(); i++) {
		Edge next = v[index][i];

		// 방문할 수 있는가?
		// 방문 하지 않았으면 방문할 수가 있음
		if (!checked[next.target]) {
			// 방문
			DFS(next.target, sum + next.weight, false);
		}
	}
	// 체크아웃
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
		// 현재 노드가 트리의 말단 노드인 경우에 DFS 탐색
		if (v[i].size() == 1) {
			DFS(i, 0, true);
		}
	}

	cout << answer << "\n";
	return 0;
}