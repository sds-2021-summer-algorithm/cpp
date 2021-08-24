#include <iostream>

using namespace std;

int N, M;
int parent[201];

int _find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = _find(parent[a]);
}

void _union(int a, int b) {
    int pa = _find(a);
    int pb = _find(b);
    parent[pb] = pa;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int tmp;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> tmp;
            if (tmp) _union(r, c);
        }
    }

    cin >> tmp;
    int root = _find(tmp);

    for (int i = 1; i < M; i++) {
        cin >> tmp;
        if (_find(tmp) != root) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
    return 0;
}