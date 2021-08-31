def make_prime():
    tmp = [[i, True] for i in range(2, 3000)]
    
    for num, isPrime in tmp:
        if isPrime:
            for mul in range(num*2, 3000, num):
                tmp[mul-2][1] = False
    
    ret = []
    for num, isPrime in tmp:
        if isPrime:
            ret.append(num)
    return ret

def dfs(start, selected, nums, primes):
    if len(selected) == 3:
        if sum(selected) in primes:
            return 1
        else:
            return 0
    cnt = 0
    
    for i in range(start, len(nums)):
        selected.append(nums[i])
        cnt += dfs(i+1, selected, nums, primes)
        selected.pop()
    
    return cnt
    
def solution(nums):
    primes = make_prime()
    
    return dfs(0, [], nums, primes)