#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void parse(string& s,vector<int>& values,string& delimiter){
    int pos = 0;
    string token;
    while((pos=s.find(delimiter))!=string::npos){
        int num =stoi(s.substr(0,pos));
        values.push_back(num);
        s.erase(0,pos+delimiter.length());
    }
    int num= stoi(s.substr(0,s.size()));
    values.push_back(num);
}
string solution(string s) {
    string answer = "";
    vector<int> values;
    string delimiter(" ");
    parse(s,values,delimiter);
    sort(values.begin(),values.end());
    int min_value=values[0];
    int max_value=values[values.size()-1];
    answer+=to_string(min_value)+" "+to_string(max_value);
    
    return answer;
}
