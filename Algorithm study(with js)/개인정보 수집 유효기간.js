function solution(today, terms, privacies) {
    var answer = [];
    let [year,month,day] = today.split('.');
    let arr = [];
    
    console.log(year,month,day);
    
    // terms 종류와 유효기간 분리 후 arr에 저장
    for(let i=0;i<terms.length;++i){
        let [kind,deadLine] =terms[i].split(' ');
        arr[kind] = deadLine;
    }
    
    for(let i=0;i<privacies.length;++i){
        let theKind = privacies[i].substring(privacies[i].length-1,privacies[i].length);
        let [year1,month1,day1] = privacies[i].substring(0,privacies[i].length-2).split('.');
        //비교해서 값을 더해주는 과정
        // if(Object.keys(arr).indexOf(theKind)!==-1){
            let result = parseInt(month1)+parseInt(arr[theKind]);
            console.log(result);
            if(result >12){
                let tmp = Math.floor((result-1)/12);
                year1 = ((parseInt(year1))+tmp);
                if(result%12===0)month1 = 12;
                else month1 = result%12;
                day1 = parseInt(day1);
            }
            else {
                month1 = parseInt(month1)+parseInt(arr[theKind]);
                day1 = parseInt(day1);
            }
            console.log(year1,month1,day1);
            //오늘 연도보다 유효기간 연도가 전이면 파기.
            if(parseInt(year1)<parseInt(year)){
                answer.push(i+1);
            }
            //오늘 연도랑 유효기간 연도랑 동일할 경우
            else if(parseInt(year1)==parseInt(year)){
                //이번달보다 유효기간달이 작다면 파기.
                if(parseInt(month1)<parseInt(month)){
                    answer.push(i+1);
                }
                //이번달과 유효기간달이 동일할 경우
                else if(parseInt(month1)==parseInt(month)){
                    // 오늘 일보다 유효기간일이 같거나 적을 경우 파기.
                    if(parseInt(day1)<=parseInt(day)){
                        answer.push(i+1);
                    }
                }
            }
            
        }
    // }
    answer.sort((a,b)=>{
        return a-b;
    })
    return answer;
}
