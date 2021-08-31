def solution(record):
    answer = []
    idTable = {}
    
    for message in record:
        message = message.split()
        if message[0] == 'Enter' or message[0] == 'Change':
            idTable[message[1]] = message[2]
    
    for message in record:
        message = message.split()
        if message[0] == 'Enter':
            answer.append(idTable[message[1]] + '님이 들어왔습니다.')
        elif message[0] == 'Leave':
            answer.append(idTable[message[1]] + '님이 나갔습니다.')
            
    return answer