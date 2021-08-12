#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int T, N, M, A[1001], B[1001];
long long ans;
vector<int> subA, subB;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < N; i++) {	//A의 부배열 합
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			subA.push_back(sum);
		}
	}
	for (int i = 0; i < M; i++) {	//B의 부배열 합
		int sum = 0;
		for (int j = i; j < M; j++) {
			sum += B[j];
			subB.push_back(sum);
		}
	}
	sort(subA.begin(), subA.end());	//오름차순
	sort(subB.rbegin(), subB.rend()); //내림차순
	
	int left = 0, right = 0;
	while (left < subA.size() && right < subB.size()) {
		if (subA[left] + subB[right] < T)
			left++;
		else if (subA[left] + subB[right] > T)
			right++;
		else {	//subA + subB == T
			long long cntA = 1, cntB = 1;
			for (int i = left + 1; i < subA.size(); i++) {	//중복되는 원소 개수 구하기
				if (subA[i] == subA[left])
					cntA++;
				else
					break;
			}
			for (int i = right + 1; i < subB.size(); i++) {	//중복되는 원소 개수 구하기
				if (subB[i] == subB[right])
					cntB++;
				else
					break;
			}
			left += cntA; right += cntB;
			ans += cntA * cntB;
		}
	}
	cout << ans << "\n";
}
