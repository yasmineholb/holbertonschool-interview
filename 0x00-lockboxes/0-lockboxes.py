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
    if boxes == []:
        return False
    elif boxes[0] == []:
        return False
    else:
        graph = {i: boxes[i] for i in range(len(boxes))}
        visited = []
        return len(dfs(visited, graph, 0)) == len(boxes)
