function solution(cap, n, deliveries, pickups) {
    var answer = 0;
    let give = 0;
    let get = 0;
    for(let i=n-1;i>=0;--i){
        if(deliveries[i]!=0 || pickups[i]!=0)
            {
                let cnt = 0;
                while(give < deliveries[i] || get< pickups[i])
                {
                    ++cnt;
                    give+=cap;
                    get+=cap;
                }
                give -= deliveries[i];
                get -=  pickups[i];
                answer = answer + ((i+1)*cnt*2);
            }
    }
    return answer;
}
