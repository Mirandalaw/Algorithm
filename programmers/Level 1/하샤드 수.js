function solution(x) {
    let ans=0;
    let a= x;
    while(a!==0){
        ans+=(a%10);
        a = Math.floor(a/10);
    }
    return x%ans===0 ? true : false;
}
