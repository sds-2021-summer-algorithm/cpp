#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0;
    
    while(index < progresses.size()){
        for(int i = 0 ; i < progresses.size(); i++){
            progresses[i] += speeds[i];
        }
        int cnt = 0;
        
        // 포인터는 progresses 배열을 초과하면 안되므로..
        // 100퍼 이상 성공하면 cnt를 증가시켜서 개수를 센다.
        while(index <progresses.size() && progresses[index] >= 100){
            cnt++;
            index++;
        }
        if(cnt != 0) answer.push_back(cnt);
    }
    
    return answer;
}