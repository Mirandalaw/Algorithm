function solution(n) {
    let answer = 0;
    let b=[]
    while(n!=0){
        b.push(n%3);
        n=Math.floor(n/3)
    }
    
    console.log(b);
    
    for(let i=b.length-1,j=0;i>=0;--i){
        let a= Math.pow(3,j);
        answer+=(b[i]*a);
        j++;
    }
    
    return answer;
}
