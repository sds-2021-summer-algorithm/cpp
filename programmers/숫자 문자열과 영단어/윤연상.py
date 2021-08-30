numdict = {
    'zero' : 0, 'one' : 1, 'two' : 2, 'three' : 3, 'four' : 4, 
    'five' : 5, 'six' : 6, 'seven' : 7, 'eight' : 8, 'nine' : 9
}
number = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

def solution(s):
    answer = 0
    idx = 0
    tmp = []
    
    while idx < len(s):
        if s[idx] in number:
            answer = answer*10 + int(s[idx])
        else:
            tmp.append(s[idx])
            word = ''.join(tmp)
            if word in numdict:
                answer = answer * 10 + numdict[word]
                tmp = []
        idx += 1
                
    return answer