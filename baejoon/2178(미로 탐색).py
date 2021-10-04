import queue


def bfs(x,y):
    q=queue()
    q.append(x,y)
    visiteid_list[y][x]=1
    while q:

N,M = map(int,input().split())
maze = [list(map(int, input())) for _ in range(N)]
visiteid_list=maze

# def bfs(v):
#     q=Deque()
#     q.append(v)
#     visited_list[v]=1
#     while q:
#         v=q.popleft()
#         print(v,end=" ")
#         for i in range(1,n+1):
#             if visited_list[i]==0 and graph[v][i]==1:
#                 q.append(i)
#                 visited_list[i]=1