#include<bits/stdc++.h>
using namespace std;
int N, input;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        if(input != 0) pq.push(input);
        else{
            if(pq.size()){
                cout << pq.top() << "\n";
                pq.pop();
            }
            else cout << 0 << "\n";
        }
    }
}