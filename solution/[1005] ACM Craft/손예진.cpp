#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

//DAG 문제

typedef struct Building{
	int time, indegree = 0, ans = 0;
};

int T, N, K, W;
queue<int> q;

void Build(vector<int> graph[], Building building[]) {	//모든 건물을 짓기위해서 각각 필요한 시간 계산
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		building[now].ans += building[now].time;	//now를 위한 선행 건물들을 모두 건설했을 때 필요한 최대 시간 + now를 짓는데 필요한 시간
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			building[next].ans = max(building[now].ans, building[next].ans);	//now의 선행건물들을 건설하는 동안 필요한 최대 시간 갱신
			if (!--building[next].indegree) {	//now를 위한 선행 건물들을 모두 건설했다면 now의 시간 더해준 뒤 그 이후의 건물들 짓기
				q.push(next);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		//초기화 중요
		vector<int> graph[1001];
		Building building[1001];
		for (int i = 1; i <= N; i++) {
			cin >> building[i].time;
		}
		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			building[Y].indegree++;
			graph[X].push_back(Y);
		}
		cin >> W;
		for (int i = 1; i <= N; i++) {
			if (!building[i].indegree)
				q.push(i);
		}
		Build(graph, building);
		cout << building[W].ans << "\n";
	}
}
