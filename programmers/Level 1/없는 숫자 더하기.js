
//나의 풀이 
function solution(numbers) {
    var answer = 45;
    for (var value of numbers) {
        answer-=value
    }
    return answer;
}

//다른 사람의 풀이
function solution(numbers) {
    return 45 - numbers.reduce((cur, acc) => cur + acc, 0);
}

function solution(numbers) {
    let answer = 0;

    for(let i = 0; i <= 9; i++) {
        if(!numbers.includes(i)) answer += i;
    }

    return answer;
}
