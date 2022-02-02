function solution(s) {
    if(s.length===4||s.length===6){
        let answer= true;
        for(let i=0;i<s.length;++i){
            if(Number.isInteger(parseInt(s.substr(i,1)))===false){
                answer=false;
            }
        }
        return answer;
    }
    else return false;
}
