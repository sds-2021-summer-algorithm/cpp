#include <iostream>

using namespace std;

int N, M;
int* parent;

int _find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = _find(parent[a]);    
}

void _union(int a, int b) {
    int pa = _find(a);
    int pb = _find(b);

    parent[pb] = pa;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt", "r", stdin);

    cin >> N >> M;

    parent = new int[N + 1];
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    int cmd, a, b;
    for (int i = 0; i < M; i++) {
        cin >> cmd >> a >> b;

        if (cmd == 0) {
            if (_find(a) != _find(b)) {
                _union(a, b);
            }
        }
        else {
            if (_find(a) == _find(b)) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}