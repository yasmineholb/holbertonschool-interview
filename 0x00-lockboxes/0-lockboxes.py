#!/usr/bin/python3
""" boxes """


def tests(boxes):
    cles = []
    b = 1
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


def iterative_dfs(graph, start):
    stack, path = [start], []
    while stack:
        vertex = stack.pop()
        if vertex in path:
            continue
        path.append(vertex)
        for neighbor in graph[vertex]:
            stack.append(neighbor)
    return path


def canUnlockAll(boxes):
    b = tests(boxes)
    if b == 0:
        return False
    else:
        graph = {i: boxes[i] for i in range(len(boxes))}
        return len(iterative_dfs(graph, 0)) == len(boxes)
