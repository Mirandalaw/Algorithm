N,M=list(map(int,input().split()))
num_list = list(map(int, input().split()))
arr = [list(map(int, input().split())) for _ in range(N)]
cost=0
for i in range(0,M-1):
    cost+=arr[num_list[i]-1][num_list[i+1]-1]

print(cost)