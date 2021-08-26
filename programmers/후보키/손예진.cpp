#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

//해당 집합의 모든 부분 집합에 대한 탐색을 마친 뒤 해당 조합을 탐색하기 때문에, 자신의 부분 집합의 정답 여부만 확인하면 됨
bool isPos(vector<int> ans, int target){     //최소성 확인
    for(int i = 0; i < ans.size(); i++){
        if((ans[i] & target) == ans[i]){    //"ans[i] & target" 묶어주는 괄호 없으면 == 먼저 실행됨
           return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    vector<int> ans;
    int colSize = relation[0].size();
    int rowSize = relation.size();
    
    for(int i = 1; i < (1 << colSize); i++){    //가능한 모든 조합의 경우의 수에 대해 탐색
        set<string> s;  //각 조합에 대한 유일성 여부 확인을 위한 집합 - set은 중복 허용 X
        for(int j = 0; j < rowSize; j++){   //모든 튜플에 대해 탐색
            string target = "";
            for(int k = 0; k < colSize; k++){   //모든 컬럼에 대해 탐색
                if(i & (1 << k)){   //현재 탐색중인 조합에 해당되는 컬럼인 경우
                    target += relation[j][k];
                }
            }
            s.insert(target);
        }
        if(s.size() == rowSize && isPos(ans, i))
            ans.push_back(i);
    }
    return ans.size();
}
