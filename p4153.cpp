#include<bits/stdc++.h>
using namespace std;
int a, b, c;
priority_queue<int> pq;
int main(){
    while(true){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        pq.push(a), pq.push(b), pq.push(c);
        a = pq.top(), pq.pop();
        b = pq.top(), pq.pop();
        c = pq.top(), pq.pop();
        if(pow(a, 2) == pow(b, 2) + pow(c, 2)) cout << "right\n";
        else cout << "wrong\n";
    }
}