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


def iterative_dfs(graph, start, m):
    """ function """
    stack, path = [start], []
    while stack:
        vertex = stack.pop()
        if vertex in path:
            continue
        if vertex < m:
            path.append(vertex)
            for neighbor in graph[vertex]:
                stack.append(neighbor)
    return path


def canUnlockAll(boxes):
    """function """
    b = tests(boxes)
    m = len(boxes)
    if b == 0:
        return False
    else:
        graph = {i: boxes[i] for i in range(len(boxes))}
        return len(iterative_dfs(graph, 0, m)) == len(boxes)
