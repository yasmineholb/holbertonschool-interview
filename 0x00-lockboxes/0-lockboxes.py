#!/usr/bin/python3
""" boxes """


def tests(boxes):
    """ function """
    cles = []
    b = 1
    if not boxes:
        return 0
    if boxes == [[]]:
        return b
    elif boxes == []:
        return 0
    elif boxes[0] == [] or boxes[0] == [0]:
        return 0
    else:
        for i in range(len(boxes)):
            for j in range(len(boxes[i])):
                cles.append(boxes[i][j])
        cles = set(cles)
        if 0 in cles:
            cles.pop()
        cles = list(cles)
        if max(cles) > len(boxes)-1:
            b = 0
        if len(cles) < len(boxes)-1:
            b = 0
        return(b)


def dfs(visited, graph, node):
    """ function """
    if node not in visited:
        visited.append(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)
    return visited


def canUnlockAll(boxes):
    """ Function """
    b = tests(boxes)
    if b == 0:
        return False
    else:
        graph = {i: boxes[i] for i in range(len(boxes))}
        visited = []
        return len(dfs(visited, graph, 0)) == len(boxes)
