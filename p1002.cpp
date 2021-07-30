#include<bits/stdc++.h>
using namespace std;
int T;
int x, y, r1, x2, y2, r2, cnt;
vector<int> answer;
int main(){
    cin >> T;
    while(T--){
        cin >> x >> y >> r1 >> x2 >> y2 >> r2;
        int dist = (x - x2) * (x - x2) + (y - y2) * (y - y2);
        int d1 = (r1 + r2) * (r1 + r2);
        int d2 = (r1 - r2) * (r1 - r2);
        if(dist == 0)
            if(d2 == 0) cnt = -1;
            else cnt = 0;
        else
            if(dist == d1 || dist == d2) cnt = 1;
            else if(dist < d1 && dist > d2) cnt = 2;
            else cnt = 0;
        answer.push_back(cnt);
    }
    for(int a : answer) cout << a << "\n";
}