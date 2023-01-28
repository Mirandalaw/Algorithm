function solution(k, tangerine) {
    var answer = 0;
    let cnt = 1;
    let arr = [];
    let N = 0;
    tangerine.sort();
    for(let i=0;i<tangerine.length;++i){
        if(tangerine[i]==tangerine[i+1]) cnt++;
        else {
            arr[N]= [tangerine[i],cnt];
            cnt=1;
            N++;
        }
    }
    arr.sort((a,b)=>{
        return b[1]-a[1];
    })
    console.log(arr);
    for(let i=0;i<arr.length;++i){
        answer++;
        if(k>arr[i][1]) k-=arr[i][1];
        else break;
    }
    return answer;
}
