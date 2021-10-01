from typing import Deque
import sys
read =sys.stdin.readline

def bfs(v):
    q=Deque()
    q.append(v)
    visited_list[v]=1
    while q:
        v=q.popleft()
        print(v,end=" ")
        for i in range(1,n+1):
            if visited_list[i]==0 and graph[v][i]==1:
                q.append(i)
                visited_list[i]=1

def dfs(v):
    visited_list2[v]=1
    print(v,end=" ")
    for i in range(1,n+1):
        if visited_list2[i]==0 and graph[v][i]==1:
            dfs(i)

n,m,v=map(int,read().split())

graph=[[0]*(n+1)for _ in range(n+1)]
visited_list=[0]*(n+1)
visited_list2=[0]*(n+1)

for _ in range(m):
    a,b =map(int,read().split())
    graph[a][b]=graph[b][a]=1

dfs(v)
print()
bfs(v)
