function solution(arr1, arr2) {
    var answer = [[]];
    let start_num=0;
    answer.splice(0, answer.length);
    while(start_num!==arr1.length){
        let start_num2=0;
        let ans = [];
        while(start_num2!==arr2[0].length){
            let sum=0;
            for(let col=0;col<arr2.length;++col){
                sum+=(arr1[start_num][col]*arr2[col][start_num2]);
            }
            ans.push(sum);
            start_num2++;
        }
        answer.push(ans);
        start_num++;
    }
    
    return answer;
}
