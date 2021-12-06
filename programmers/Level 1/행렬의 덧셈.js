//다른사람의 풀이
const matrixAddition = (matrix1, matrix2) =>
  matrix1.map((row, y) =>
    row.map((v, x) => v + matrix2[y][x]));

function solution(arr1, arr2) {
    return matrixAddition(arr1, arr2);
}

//나의 풀이

function solution(arr1, arr2) {
    let answer = [];
    for(let i=0;i<arr1.length;++i){
        let arr=[];
        for(let j=0;j<arr1[i].length;++j){
            arr.push(arr1[i][j]+arr2[i][j]);
        }
        answer.push(arr);
    }
    return answer;
}
