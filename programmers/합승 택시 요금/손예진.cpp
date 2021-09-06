#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 100000000

using namespace std;

vector<pair<int, int>> graph[201];
int dist[201][201];

void floyd(int n) { //모든 노드간의 거리 계산
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int simulation(int n, int s, int a, int b) {    //최적의 택시비 계산
    int ans = 0x7FFFFFFF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    return ans;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i != j)  //동일한 노드간의 거리는 0이 돼야함
                dist[i][j] = MAX;
        }
    }
    for (int i = 0; i < fares.size(); i++) {
        int c = fares[i][0], d = fares[i][1], f = fares[i][2];
        dist[c][d] = f;
        dist[d][c] = f;
    }
    floyd(n);
    answer = simulation(n, s, a, b);
    return answer;
}
