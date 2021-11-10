#include <string>
#include <vector>

using namespace std;
int map[101][101];
int Min(int A, int B) { return A < B ? A : B; }

int turn(int x,int y,int xx,int yy)
{
    int minNum;
    int temp=map[x][y];
    minNum=temp;
    for(int i=x;i<xx;++i){
        minNum=Min(minNum,map[i][y]);
        map[i][y]=map[i+1][y];
    }
    for(int i=y;i<yy;++i){
        minNum=Min(minNum,map[xx][i]);
        map[xx][i]=map[xx][i+1];
    }
    for(int i=xx;i>x;--i){
        minNum=Min(minNum,map[i][yy]);
        map[i][yy]=map[i-1][yy];
    }
    for(int i= yy;i>y;--i){
        minNum=Min(minNum,map[x][i]);
        map[x][i]=map[x][i-1];
    }
    map[x][y+1]=temp;
    return minNum;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int number=1;
    for(int i=0;i<rows;++i){
        for(int j=0;j<columns;++j){
            map[i][j]=number++;
        }
    } 
    vector<int> answer;
    for(int i=0;i<queries.size();++i){
        int x=queries[i][0];
        x--;
        int y=queries[i][1];
        y--;
        int xx=queries[i][2];
        xx--;
        int yy=queries[i][3];
        yy--;
        
        answer.push_back(turn(x,y,xx,yy));
    }
   
    return answer;
}
