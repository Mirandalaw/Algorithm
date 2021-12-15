function solution(n) {
    const a="수박";
    let answer="";
    let tmp = Math.floor(n/2);
    for(let i =0;i<tmp;++i){
        answer+=a;
    }
    if(n%2!==0)answer+=a[(n%2)-1];
    return answer;
}
