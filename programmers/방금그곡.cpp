#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string change(string &in,map<string,char> &s){
    string out = "";
    
    for(int i=0;i<in.size();++i){
        if(in[i+1]=='#'){
            out+=s[in.substr(i,2)];
            i++;
        }
        else out+=in[i];
    }
    return out;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int hour1=0,hour2=0,min1=0,min2=0,resultTime=0,ans=0;
    string melody = "",title = "";
    map<string,char>s;

    s["C#"]='H';
    s["D#"]='I';
    s["F#"]='J';
    s["G#"]='K';
    s["A#"]='L';
    
    melody = change(m,s);
    
    for(int i=0;i<musicinfos.size();++i){
        string tmp ="", music = "";
        
        hour1 = stoi(musicinfos[i].substr(0,2))*60;
        min1 = stoi(musicinfos[i].substr(3,2));
        hour1 = stoi(musicinfos[i].substr(6,2))*60;
        min2 = stoi(musicinfos[i].substr(9,2));
        resultTime=(hour1+min1)-(hour2+min2);
        
        for(int j=12;musicinfos[i].size();--j){
            if(musicinfos[i][j]==',')
            {
                title = musicinfos[i].substr(12,j-12);
                tmp = musicinfos[i].substr(j+1);
                break;
            }
        }
        music= change(tmp,s);
        
        if(music.size()<resultTime){
            tmp = music;
            
            for(int j=1;j<resultTime/tmp.size();++j){
                music+=tmp;
            }
            for(int j=0;j<resultTime/tmp.size();++j){
                music+=tmp[j];
            }
        }
        else music = music.substr(0,resultTime);
        
        if(music.find(melody)!=string::npos){
            if(ans<resultTime){
                answer=title;
                ans=resultTime;
            }
        }
    }
    return answer;
}
