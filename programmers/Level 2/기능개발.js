function solution(progresses, speeds) {
    var answer = [0];
   //새로운 days라는 배열을 만들어 100-progress / speeds[index] 를 통해 각각의 progresses들이 배포가 몇일 걸리는 저장
    let days = progresses.map((progress,index)=>Math.ceil((100-progress)/speeds[index]));
    console.log(days);
    let maxDay = days[0];
    
    for(let i=0,j=0;i<days.length;++i){
        if(days[i]<=maxDay){
            answer[j]+=1;
        }else{
            maxDay=days[i];
            answer[++j]=1;
        }
    }
    return answer;
}
