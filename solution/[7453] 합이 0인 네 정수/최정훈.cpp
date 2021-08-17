#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
int* arr[4];
int* AB;
int* CD;

bool compAscend(int a, int b) {
    return a < b;
}

bool compDescend(int a, int b) {
    return a > b;
}

ll two_pointer(int idxAB, int idxCD, int arrSize) {
    ll totalCount = 0;

    while (idxAB < arrSize && idxCD < arrSize) {
        int sumAB = AB[idxAB];
        int sumCD = CD[idxCD];
        int sum = sumAB + sumCD;

        if (sum == 0) {
            int cntAB = 0, cntCD = 0;

            while (idxAB < arrSize && AB[idxAB] == sumAB) {
                idxAB++; cntAB++;
            }
            while (idxCD < arrSize && CD[idxCD] == sumCD) {
                idxCD++; cntCD++;
            }

            totalCount += (ll)cntAB * (ll)cntCD;
        }
        else if (sum > 0) {
            idxCD++;
        }
        else {
            idxAB++;
        }
    }

    return totalCount;
}

ll solve() {
    int arrSize = N * N;
    AB = new int[arrSize];
    CD = new int[arrSize];

    int id = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB[id] = arr[0][i] + arr[1][j];
            CD[id] = arr[2][i] + arr[3][j];
            id++;
        }
    }

    sort(AB, AB + arrSize, compAscend);
    sort(CD, CD + arrSize, compDescend);
    
    ll answer = two_pointer(0, 0, arrSize);
    return answer;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("../input.txt", "r", stdin);

    cin >> N;

    for (int i = 0; i < 4; i++) {
        arr[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];
    }

    cout << solve() << endl;

    return 0;
}