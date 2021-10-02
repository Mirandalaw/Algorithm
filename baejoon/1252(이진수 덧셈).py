A, B = map(str,input().split())

A= int(A,2)
#int(A,2) 다른 진수의 문자열로 숫자형으로 변환하기
print(A)
B= int(B,2)
C= A+B
print(bin(C)[2:])

# bin(number)
# 전달받은 integer 혹은 long integer 자료형의 값을 이진수(binary) 문자열로 돌려줌