from collections import defaultdict

def dfs(n, cur, path, graph):
    if len(path) == n+1:
        return path
    
    for i, nex in enumerate(graph[cur]):
        path.append(graph[cur].pop(i))
        ret = dfs(n, nex, path, graph)
        graph[cur].insert(i, nex)
        
        if ret:
            return ret
        else:
            path.pop(-1)

def solution(tickets):
    graph = defaultdict(list)
    
    for start, end in tickets:
        graph[start].append(end)
        graph[start].sort()
        
    return dfs(len(tickets), 'ICN', ['ICN'], graph)