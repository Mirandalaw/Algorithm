def solution(numbers):
    answer = 0
    num=[1,2,3,4,5,6,7,8,9]
    visited =[0]*10
    for i in numbers:
        visited[i]=1
    
    for i in range(0,10):
        if visited[i]==0:
            answer+=i
    return answer