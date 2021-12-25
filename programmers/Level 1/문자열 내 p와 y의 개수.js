function solution(s){
    let numberp=0;
    let numbery=0;
    let a=s.toUpperCase(); //소문자를 대문자로 바꿔주는 함수
    for(let i in a){
        if(a[i]==='P')numberp++;
        else if(a[i]==='Y')numbery++;
    }
    if(numberp===numbery)return true;
    else return false;
}
