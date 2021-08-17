#include <iostream>
#include <algorithm>
#define LEN 19
using namespace std;

const int dx[] = {1, 1, 1, 0}, dy[] = {-1, 0, 1, 1};
int _map[20][20], ans_color;
pair<int, int> ans;
int ans_x, ans_y;

int check(int y, int x, int way, int color) {
    int cnt = 1, ny, nx;
    
    ny = y + dy[way]; nx = x + dx[way];
    while(_map[ny][nx] == color) { cnt++; ny += dy[way]; nx += dx[way]; }
    
    ny = y - dy[way]; nx = x - dx[way];
    while(_map[ny][nx] == color) { cnt++; ny -= dy[way]; nx -= dx[way]; }
    
    if(cnt == 5) {
        if(x > nx + dx[way]) {
            ans_x = nx + dx[way];
            ans_y = ny + dy[way];
        } else { ans_x = x; ans_y = y; }
        return true;
    } return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int y = 1; y <= LEN; y++)
    for(int x = 1; x <= LEN; x++) cin >> _map[y][x];
    
    for(int y = 1; y <= LEN; y++)
    for(int x = 1; x <= LEN; x++) {
        if(!_map[y][x]) continue;
        
        for(int w = 0; w < 4; w++) {
            if(check(y, x, w, _map[y][x])) {
                cout << _map[y][x] << '\n';
                cout << ans_y << ' ' << ans_x;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}