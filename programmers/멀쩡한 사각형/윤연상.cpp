#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int GCD(int a, int b) {         // 최대 공약수
    int r = a % b;
    if (r == 0) return b;
    else return GCD(b, r);
}

long long solution(int w, int h) {
    if (w == 1 || h == 1) return 0;

    ll ans = (ll)w * h;
    int gcd = GCD(w, h);
    w = w / gcd;            // w와 h를 최대공약수로 나눔
    h = h / gcd;            // 계산량을 줄이기 위함

    ll cnt = 0;
    double interval = (double)h / w;
    for (int i = 0; i < w; i++)
        cnt += ceil((i + 1) * interval) - floor(i * interval);

    return ans - cnt * gcd;
}