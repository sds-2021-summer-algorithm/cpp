#include <iostream>
#include <string>
#include <vector>

/*
<difficulty>
문자열의 약수개로만 자를 수 있는줄 알았는데 관계 없었음
*/

using namespace std;

string CalcLen(string s, int len){
    string str_bef = "", str_now, str_ans = "";
    int num = 0;
    for(int i = 0; i < s.length(); i += len){
        str_now = s.substr(i, len);
        if(i == 0)   //첫 시작
            str_bef = str_now;
        else{
            if(str_now == str_bef){ //이전 문자열과 일치
                if(num == 0)
                    num = 2;
                else
                    num++;
            }
            else{ //이전 문자열과 불일치
                if(num > 0)
                    str_ans += to_string(num);
                str_ans += str_bef;
                num = 0;
                str_bef = str_now;
            }
        }
    }
    
    //마지막 문자열 처리
    if(num > 0)
        str_ans += to_string(num);
    str_ans += str_now;
  
    return str_ans;
}

int solution(string s) {
    string answer = "";
    int len = s.length();
    bool flag = false;
    for(int i = 1; i <= len / 2; i++){
        flag = true;
        string tmp = CalcLen(s, i);
        if(answer.length() == 0 || tmp.length() < answer.length()){
            answer = tmp;
        }
    }
    if(!flag) //for문을 한 번도 돌지 못할 경우 (ex 문자열의 길이가 1)
        answer = s;
    return answer.length();
}
