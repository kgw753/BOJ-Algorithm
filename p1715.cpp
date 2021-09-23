#include<bits/stdc++.h>
using namespace std;
int N, num;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        pq.push(num);
    }
    int sum = 0;
    int tmp;
    while(pq.size() > 1){
        tmp = 0;
        tmp += pq.top(); pq.pop();
        tmp += pq.top(); pq.pop();
        pq.push(tmp);
        sum += tmp;
    }
    cout << sum << "\n";
}