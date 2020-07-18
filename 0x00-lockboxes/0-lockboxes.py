#!/usr/bin/python3
""" boxes """


def dfs(visited, graph, node):
    """function """
    if node not in visited:
        visited.append(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)
    return visited


def canUnlockAll(boxes):
    """ box """
    lis = []
    for i in range(len(boxes)):
        for j in range(len(boxes[i])):
            lis.append(boxes[i][j])
    lis = set(lis)
    for i in range(1, len(boxes)):
        if i not in lis:
            return False
            break
    if boxes == []:
            return False
    elif boxes[0] == []:
        return False
    else:
        graph = {i: boxes[i] for i in range(len(boxes))}
        visited = []
        return len(dfs(visited, graph, 0)) == len(boxes)
