function solution(s, n) {
    var answer = '';
    for(let i=0;i<s.length;++i){
        let ch = s[i].charCodeAt();
        if(ch!==32){
            if(97<=ch&&ch<123){ //소문자인 경우 아스키 코드값의 범위를 넘어갈 수 있기 때문에
                ch-=32;
                ch+=n;
                if(ch>=91)ch-=26;
                ch+=32;
            }
            else if(65<=ch&&ch<=90){
                ch+=n;
                if(ch>=91)ch-=26;
            }
            let ans= String.fromCharCode(ch);
            answer+=ans;
        }
        else answer+=" ";
    }
    return answer;
}
