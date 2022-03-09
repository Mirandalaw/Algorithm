function solution(s)
{
    const stack = [];
    //1. 비어있거나 s[i-1]번째 원소가 s[i]번쨰 원소와 다른 경우 push
    //2. 비어있지x s[i-1]번째 원소가 s[i]번째 원소와 같은 경우 pop
    for(let i=0;i<s.length;++i){
        if(!stack.length||stack[stack.length-1]!==s[i])stack.push(s[i]);
        else stack.pop();
    }
    return stack.length ? 0:1;
}
