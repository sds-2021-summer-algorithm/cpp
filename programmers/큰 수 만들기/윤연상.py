def solution(number, k):
    answer = []
    idx = 0
    
    while idx + k < len(number) and k != 0:
        flag = True
    
        for i in range(1, k+1):
            if number[idx] == '9':
                break
            if number[idx] < number[idx+i]:
                idx += i
                k -= i
                flag = False
                break
        
        if flag:
            answer.append(number[idx])
            idx += 1
            
    if (k == 0):
        return ''.join(answer) + number[idx:]
    else:
        return ''.join(answer)