process.stdin.setEncoding('utf8');
process.stdin.on('data', data => {
    const n = data.split(" ");
    const a = Number(n[0]), b = Number(n[1]);
    for(let i =0;i<n[1];++i){
        for(let j=0;j<n[0];++j){
            process.stdout.write('*');//console.log를 하면 자동으로 줄바꿈이 되기 때문에 앞의 코드와 같이 
        }
        console.log();
    }
});
