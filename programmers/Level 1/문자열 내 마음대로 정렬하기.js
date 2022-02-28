function solution(strings, n) {
    return strings.sort((a,b)=>{
        let first = a.charCodeAt(n);
        let second = b.charCodeAt(n);
        
        if(first === second)
            return a.localeCompare(b);
        else return first -second;
    })
}
