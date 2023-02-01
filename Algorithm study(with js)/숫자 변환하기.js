function solution(x, y, n) {
    if(x==y) return 0;
    // dp 는 y까지의 값을 저장
    const dp = {};
    // data는 값을 저장
    let data = [];
    data = [x];
    dp[x] = 0;
    while(data.length){
        let newData = [];
        for(const d of data){
            for(const makeData of [d+n,d*2,d*3]){
                //makeData가 y보다 크거나 dp[makeData] 가 undefined
                if(makeData > y ||dp[makeData]) continue;
                if(makeData==y) return dp[d]+1;
                dp[makeData] = dp[d] +1;
                newData.push(makeData);
            }
        }
        data=newData;

    }
    return -1;
}
