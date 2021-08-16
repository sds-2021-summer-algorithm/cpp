#include <iostream>
using namespace std;
int N, M, I, ans;
bool flag = true, map[2][51][51];


int main() {
    scanf("%d %d", &N, &M);
    for(int t = 0; t < 2; t++) for(int n = 1; n <= N; n++) {
        for(int m = 1; m <= M; m++) {
            scanf("%1d", &I);
            map[t][n][m] = (I == 1);
        }
    }
    
    for(int n = 1; n <= N; n++) {
        for(int m = 1; m <= M; m++) {
            if(map[0][n][m] == map[1][n][m]) continue;
            if(m > M - 2 || n > N - 2) {
                flag = false;
                break;
            }
            ans ++;
            for(int y = 0; y < 3; y++) for(int x = 0; x < 3; x++) {
                int ny = n + y, nx = m + x;
                map[0][ny][nx] = !map[0][ny][nx];
            }
        }
    }
    
    for(int n = N - 2; n <= N; n++) for(int m = M - 2; m <= M; m++)
        if(map[0][n][m] != map[1][n][m]) { flag = false; break; }
    
    printf("%d", flag ? ans : -1);
    
    return 0;
}