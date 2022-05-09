function solution(n, lost, reserve) {
    let student = new Array(n+1).fill(1);
    student[0]=0;
    for(let i=1;i<=lost.length;++i){
        student[lost[i-1]]-=1;
    }
    for(let i=1;i<=reserve.length;++i){
        student[reserve[i-1]]+=1;
    }
    let answer = student.filter(n=>n!==0).length;
    for(let i=1;i<=n;++i){
        if(student[i]===0&&student[i+1]===2||student[i+1]===0&&student[i]===2){
            student[i]=1;
            student[i+1]=1;
            answer++;
        }
    }
    return answer;
}
// 또 다른 풀이
function solution(n, lost, reserve) {
    var answer = 0;
    let arr= new Array(n).fill(1);
    for(let i=0;i<lost.length;++i){
        arr[lost[i]-1]--;
    }
    for(let i=0;i<reserve.length;++i){
        arr[reserve[i]-1]++;
    }
    for(let i=0;i<n;++i){
        if(arr[i]==0){
            if(arr[i-1]==2){
                arr[i]++;
                arr[i-1]--;
            }
            else if(arr[i+1]==2){
                arr[i]++;
                arr[i+1]--;
            }
        }
        if(arr[i]>=1)answer++;
    }
   
    return answer;
}
