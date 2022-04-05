function solution(id_list, report, k) {
    let arr = new Array(id_list.length).fill(0);
    // console.log(arr);
    let report_list = [];
    id_list.map((value)=>{
        report_list[value]=[];
    })
    report.map((value)=>{
        const [user_id,report_id] = value.split(" ");
        if(!report_list[report_id].includes(user_id)) report_list[report_id].push(user_id);
    })
    let cnt=0;
    for(let value in report_list){
        if(report_list[value].length>=k){
           report_list[value].map((user)=>{
                arr[id_list.indexOf(user)] += 1
           })
        }
    }
    return arr;
}

function solution(id_list, report, k) {
    // 새로운 id_list의 길이 만큼의 answer 배열을 0으로 초기화
    const answer = new Array(id_list.length).fill(0);
    let userList = [];
    id_list.map((value)=>{
        userList[value]= [];
    })
    report.map(value=>{
        const [user_id,report_id]=value.split(' ');
        if(!userList[report_id].includes(user_id))userList[report_id].push(user_id);
    })
    for(const key in userList){
        if(userList[key].length>=k){
            userList[key].map(v=>{
                answer[id_list.indexOf(v)]++;
            })
        }
    }
    return answer;
}
