#include<iostream>
using namespace std;

int main()
{
    int count = 0;
    while (1)
    {
        int L, P, V; 
        int answer = 0;
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)break;
        else count++;
        if ((V%P)>L) answer = (V / P * L) + L;
        else answer = (V / P )* L + V%P;
        cout << "Case" <<" "<<count <<":" <<" "<< answer << endl;
    }
    return 0;
}
