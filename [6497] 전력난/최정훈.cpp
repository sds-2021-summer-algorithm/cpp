#include <iostream>
#include <vector>
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

void _union(int a, int b);
int _find(int a);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int M, N;
    int src, dst, cost, totalSum;

    while (true) {
        cin >> M >> N;

        // check if end
        if (M == 0 && N == 0) break;

        // initialize
        edgeList = new Edge[N];
        parent = new int[M];
        for (int i = 0; i < M; i++) {
            parent[i] = i;
        }

        // get input
        int totalSum = 0;
        for (int i = 0; i < N; i++) {
            cin >> src >> dst >> cost;
            edgeList[i] = Edge(src, dst, cost);
            totalSum += cost;
        }

        // sort edge list, ascending order of cost
        sort(edgeList, edgeList + N, comp);

        // Kruskal
        int selected = 0;
        int costSum = 0;
        for (int i = 0; i < N; i++) {
            Edge edge = edgeList[i];
            // MST has (vertex - 1) edges
            if (selected == M - 1) break;

            // if both point not in same group
            if (_find(edge.src) != _find(edge.dst)) {
                selected++;
                costSum += edge.cost;
                _union(edge.src, edge.dst);
            }
        }
        
        // cost sum of unselected edges
        cout << totalSum - costSum << '\n';                     

        // flush
        delete[] edgeList;
        delete[] parent;
    }

    return 0;
}

void _union(int a, int b) {
    int pa = _find(a);
    int pb = _find(b);

    parent[pb] = pa;
}

int _find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = _find(parent[a]);
}