class Solution {
public:
    int reverse(int x) {
        long long answer =0;
        
        long long ab = abs(x);
       // cout << ab;
        while(ab >0){
            answer *= 10;
            answer += (ab %10);
            ab /= 10;
        }
        
        if(answer >= INT_MAX){
            answer = 0;
        }
        
        if(x < 0){
            answer = -answer;
        }
        
        return answer;
    }
};