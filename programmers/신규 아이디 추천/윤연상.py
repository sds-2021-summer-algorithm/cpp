from collections import deque

def removeDot(new_dq):
    while new_dq:
        if new_dq[-1] == '.':
            new_dq.pop()
        else:
            break
    while new_dq:
        if new_dq[0] == '.':
            new_dq.popleft()
        else:
            break
    return new_dq

def solution(new_id):
    # 1단계
    new_id = new_id.lower()
    
    # 2단계
    dq = deque()
    for ch in new_id:
        if ch.isdigit() or ch.isalpha() or ch == '_' or ch == '-' or ch == '.':
            dq.append(ch)
    
    # 3단계
    new_dq = deque([dq[0]])
    for i in range(1, len(dq)):
        if new_dq[-1] == '.' and dq[i] == '.':
            continue
        new_dq.append(dq[i])
    del dq
    
    # 4단계
    removeDot(new_dq)
    
    # 5단계
    if not new_dq:
        return "aaa"
    
    # 6단계
    length = len(new_dq)
    if length > 15:
        for _ in range(length - 15):
            new_dq.pop()
    # 7단계
    elif len(new_dq) < 3:
        for _ in range(3 - length):
            new_dq.append(new_dq[-1])
            
    removeDot(new_dq)
            
    return ''.join(new_dq)