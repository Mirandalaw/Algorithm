function solution(s) {
    return s.split("").sort().reverse().join("");
}
/*
    split()을 통해 문자열을 잘라 배열로 만듭니다.
    sort()는 유니코드 순으로 정렬해줍니다.
    reverse()는 배열을 내림차순으로 변환합니다.
    join()을 통해 배열을 합쳐 다시 문자열로 변경해줍니다.
*/
