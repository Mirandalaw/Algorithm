function solution(s) {
    // numbers 라는 배열을 만들어 숫자에 해당하는 영단어 배열을 만들어 줍니다.
    const numbers = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
    for(let i=0;i<numbers.length;++i){
        //문자열 s에서 영단어로 되어 있는 numbers 배열 탐색 후 split 수행합니다.
        let arr = s.split(numbers[i]); 
        //join 을 통해 split되어진 문자열 s를 i를 넣어주고 연결해줍니다.
        s = arr.join(i);
    }
    // 형변환을 통해 숫자로 return 합니다.
    return Number(s);
}
