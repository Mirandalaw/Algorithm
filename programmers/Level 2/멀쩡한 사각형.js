function solution(w, h) {
    var answer = w * h ; // 사각형의 넓이
    let inclination = h / w ; // 기울기
    let arr = [];
    let dp = [];
    for(let i = 0 ; i <= w ; ++i){
        arr.push(inclination*i);
    }
    let sum =0;
    for(let i=2;i<=w/2;++i){
        
        if(Number.isInteger(stans)) answer-=stans;
        else answer-=Math.ceil(stans);
    }
    return answer;
}
