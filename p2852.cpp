#include<bits/stdc++.h>
using namespace std;
int N, scr1, scr2;
int time1, time2;
void print(int n){
    int m = n / 60;
    int s = n % 60;
    printf("%02d:%02d\n", m, s);
}
int toInt(string str){
    int m = stoi(str.substr(0, 2));
    int s = stoi(str.substr(3));
    return m * 60 + s;
}
int main(){
    cin >> N;
    int team;
    string t;
    int now, prev;
    for(int i = 0; i < N; i++){
        cin >> team >> t;
        now = toInt(t);
        if(scr1 > scr2) time1 += now - prev;
        else if(scr1 < scr2) time2 += now - prev;
        team == 1 ? scr1++ : scr2++;
        prev = now;
    }
    if(scr1 > scr2) time1 += (48 * 60) - prev;
    else if(scr1 < scr2) time2 += (48 * 60) - prev;

    print(time1);
    print(time2);
}