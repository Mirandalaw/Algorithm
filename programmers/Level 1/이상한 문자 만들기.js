function solution(s) {
    let ans ='';
    let str = s.split(" ");
    for(let i =0;i<str.length;++i){
        for(let j =0;j<str[i].length;++j){
            if(j%2===0){
                ans+=str[i].substring(j,j+1).toUpperCase();
            }
            else ans+=str[i].substring(j,j+1).toLowerCase();
        }
        if(i!==str.length-1)ans+=" ";
    }
    return ans;
}
