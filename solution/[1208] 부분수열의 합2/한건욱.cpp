#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> sumList[2];
int N, M, input[41];

void getSumList(int st, int now, int ex, long long sum, int type) {
    if(now > ex) {
        sumList[type].push_back(sum);
        return;
    }
    
    getSumList(st, now + 1, ex, sum, type);
    getSumList(st, now + 1, ex, sum + input[now], type);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M; for(int n = 1; n <= N; n++) cin >> input[n];
    
    getSumList(1, 1, N / 2, 0, 0);
    getSumList(N/2 + 1, N/2 + 1, N, 0, 1);
    
    
    sort(sumList[0].begin(), sumList[0].end());
    sort(sumList[1].begin(), sumList[1].end());
    
    int l = 0, r = sumList[1].size() - 1, left_len = sumList[0].size();
    long long cnt = 0;
    
    while(l < left_len && r >= 0) {
        long long now_sum = sumList[0][l] + sumList[1][r];
        if(now_sum == M) {
            long long cnt1 = 0, cnt2 = 0;
            long long ln = sumList[0][l], rn = sumList[1][r];
            
            
            while(l < left_len && sumList[0][l] == ln) { l ++; cnt1++; }
            while(r >= 0 && sumList[1][r] ==rn) { r --; cnt2++; }
            
            cnt += cnt1 * cnt2;
        } 
        else if(now_sum > M) r--;
        else l++; 
    }
    cnt = M ? cnt : cnt - 1;
    cout << cnt;
    return 0;
}