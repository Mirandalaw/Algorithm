function solution(numbers) {
    var answer = [];
    for(let i=0;i<numbers.length;++i){
        for(let j=i+1;j<numbers.length;++j){
            answer.push(numbers[i]+numbers[j]);
        }
    }
    //*******************************
    const set = new Set(answer);
    const uniqueArr = [...set];
    //*******************************
    //=> 중복값이 있는 배열을 Set 객체로 만들어서 중복을 제거한뒤
    //Spread Operator(전개연산자)를 사용하여 Set 객체를 다시 배열로 변환
    //Spread Operator 대신 Array.from() 또는 forEach() 문 사용가능
    uniqueArr.sort((a,b)=>{
        return a-b;
    })
    return uniqueArr;
}
