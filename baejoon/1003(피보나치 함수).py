tc=int(input())
onecount=[0]*41
zerocount=[0]*41
for i in range(0,tc):
    num=int(input())
    zerocount[0]=1
    onecount[0]=0
    zerocount[1]=0
    onecount[1]=1
    for i in range(2,num+1):
        zerocount[i]=zerocount[i-1]+zerocount[i-2]
        onecount[i]=onecount[i-1]+onecount[i-2]
    print(zerocount[num],onecount[num],sep=" ")
    /seq 는 print(a,b,seq=" ") a" "b로 
    
     
