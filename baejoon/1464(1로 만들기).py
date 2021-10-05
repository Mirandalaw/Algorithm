N=int(input())

Dp=[0]*(N+1)
for i in range(2,N+1):
    Dp[i]=Dp[i-1]+1
    if i%2==0 :
        Dp[i]=min(Dp[i],Dp[i//2]+1)
    if i%3==0:
        Dp[i]=min(Dp[i],Dp[i//3]+1)

print(Dp[N])