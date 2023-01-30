function solution(maps) {
    var answer = [];
    let map = initMap(maps);
    if(map ==-1) return [-1];
    let visited = initVisited(maps);
    let dx = [0,1,0,-1];
    let dy = [-1,0,1,0];
    
  
    for(let col=0;col<maps.length;++col){
        let sum = 0;
        for(let row =0;row<maps[col].length;++row){
            if(!visited[col][row]){
                let result = bfs(row,col,visited,map,dx,dy,sum);
                if(result>0) answer.push(result);
            }
        }
    }
     
    return answer.sort((a,b)=> a-b);
}


function bfs(x,y,visited,map,dx,dy,sum){
    let queue = [];
    queue.push([x,y]);
    visited[y][x]= true;
    while(queue.length!=0){
        let q = queue.shift();
        let x = q[0];
        let y = q[1];
        for(let dir = 0;dir<4;++dir){
            let nx = x+dx[dir];
            let ny = y+dy[dir];
            if(nx>=0&&nx<map[0].length&&ny>=0&&ny<map.length){
                if(!visited[ny][nx]&&map[ny][nx]!=-1){
                    queue.push([nx,ny]);
                    visited[ny][nx]=true;
                    sum+=map[ny][nx];
                }
            }
        }
    }
    console.log(sum);
    if(sum==0){
        return -1;
    }
    else return sum;
}

function initMap(maps){
    let map = [];
    let isTrue = false;
    for(let col=0;col<maps.length;++col){
        let m = [];
        for(let row = 0; row<maps[col].length;++row){
            if(maps[col][row]==='X') m[row]=-1;
            else {
                m[row] = parseInt(maps[col][row]);
                isTrue = true;
            }
        }
        map.push(m);
    }
    if(!isTrue) return -1;
    else return map;
}
function initVisited(maps){
    let visited = [];
    for(let col=0;col<maps.length;++col){
        let visit = [];
        for(let row= 0;row<maps[col].length;++row){
            visit[row]=false;
        }
        visited.push(visit);
    }
    return visited;
}
