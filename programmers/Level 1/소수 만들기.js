function isPrime(num){
    for(let i=2;i<=Math.sqrt(num);++i){
        if(num%i===0) return false;
    }
    return true;
}
function solution(nums) {
    let answer = 0;
    for(let i=0;i<nums.length;++i){
        let sum=0;
        for(let j=i+1;j<nums.length;++j){
            for(let k=j+1;k<nums.length;++k){
                sum=nums[i]+nums[j]+nums[k];
                if(isPrime(sum)===true) answer++;
                else continue;
            }
        }
    }
    return answer;
}
