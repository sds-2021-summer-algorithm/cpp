def get_nearest(cur, position, length):
    Min = 30
    
    for pos in position:
        diff = abs(cur - pos)
        diff = min(diff, length - diff)
        if Min > diff:
            Min = diff
            ret = pos
            
    return ret, Min
    
def solution(name):
    cnt = 0
    position = []
    
    for i, ch in enumerate(name):
        diff = ord(ch) - ord('A')
        diff = min(diff, 26 - diff)
        cnt += diff
        
        if diff != 0:
            position.append(i)
            
    if not position:
        return cnt
    
    now = 0
    
    while position:
        nex, add = get_nearest(now, position, len(name))
        position.remove(nex)
        now = nex
        cnt += add
        
    return cnt