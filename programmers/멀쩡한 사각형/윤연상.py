def up(num):
    if num == int(num):
        return int(num)
    else:
        return int(num) + 1
    
def down(num): return int(num)
    
def gcd(a, b):
    r = 1
    while r:
        r = a % b
        a = b
        b = r
    return a
    

def solution(w,h):
    if w == 1 or h == 1:
        return 0
    
    ans = w*h
    div = gcd(w, h)
    w = w // div
    h = h // div
    
    cnt = 0
    for i in range(w):
        cnt += up((i+1) * h / w) - down(i * h / w)
        
    return ans - cnt * div