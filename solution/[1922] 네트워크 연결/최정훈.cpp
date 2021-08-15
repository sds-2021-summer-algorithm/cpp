#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dst, cost;

    Edge() { }
    Edge(int s, int d, int c)
        : src(s), dst(d), cost(c) { }
};

bool comp(Edge a, Edge b) {
    return a.cost < b.cost;
}

Edge* edgeList;
int* parent;

int _find(int a);
void _union(int a, int b);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int N, M;
    cin >> N >> M;

    edgeList = new Edge[M];
    parent = new int[N + 1];

    // get input
    int src, dst, cost;
    for (int i = 0; i < M; i++) {
        cin >> src >> dst >> cost;

        if (src != dst) {
            edgeList[i] = Edge(src, dst, cost);
        }
    }

    // sort edge list
    sort(edgeList, edgeList + M, comp);

    // init parent
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    // kruskal
    long long costSum = 0;
    int edgeCount = 0;
    for (int i = 0; i < M; i++) {
        if (edgeCount == N - 1) break;

        Edge edge = edgeList[i];

        if (_find(edge.src) != _find(edge.dst)) {
            _union(edge.src, edge.dst);
            costSum += (long long)edge.cost;
            edgeCount++;
        }
    }

    // print result
    cout << costSum << '\n';

    // flush
    delete[] edgeList; 
    delete[] parent; 

    return 0;
}

int _find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = _find(parent[a]);
}

void _union(int a, int b) {
    int pa = _find(a);
    int pb = _find(b);

    parent[pb] = pa;
}