#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

/*
* <idea>
* 1. 기존 순서 토대로 단방향 그래프 만들기
* 2. 순서 바뀐 팀은 그래프 방향 반대로 변경
* 3. (indegree == 0)인 팀은 순서 알 수 있음 -> ans 벡터에 추가
* <difficulty>
* 1. indegree 늘리고 줄일 때 반대로 함
* 2. order[i] = n -> i 등 한 팀이 n인데, i팀은 n등으로 착각하고 문제 풂
*/

int T, N, M;
int order[501], indegree[501], adj[501][501];

void DAG() {  //위상정렬
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	vector<int> ans;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		ans.push_back(a);
		for (int i = 1; i <= N; i++) {
			if (adj[a][i]) {
				if (--indegree[i] == 0)
					q.push(i);
			}
		}
	}
	if (ans.size() < N) {	//모든 팀에 대해 순서 알 수 없는 경우
		cout << "IMPOSSIBLE\n";
		
	}
	else {	//모든 팀에 대해 순서 알 수 있는 경우
		for (int i = 0; i < N; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		memset(adj, false, sizeof(adj));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			order[i] = n;
			indegree[n] = i;
		}
		for (int i = 0; i < N; i++) { //모든 팀들간에 단방향 그래프 생성
			for (int j = i + 1; j < N; j++) {
				adj[order[i]][order[j]] = true;
			}
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			
			if (adj[b][a])	//(a, b)는 한 번만 입력됨 => (adj[b][a] == true) -> a가 b 다음에 옴
				swap(a, b);
			indegree[a]++;
			indegree[b]--;
			adj[a][b] = false;
			adj[b][a] = true;
		}
		DAG();
	}
}
