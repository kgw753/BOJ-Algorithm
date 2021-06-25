#include<bits/stdc++.h>
using namespace std;

int T, K;

int main(){
    cin >> T;
    vector<long long> answer;
    for(int i = 0; i < T; i++){
        cin >> K;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        long long sum = 0;
        for(int j = 0; j < K; j++){
            long long input;
            cin >> input;
            pq.push(input);
        }

        long long a, b;
        
        while(pq.size() != 1){
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            sum += (a + b);
            pq.push(a + b);
        }

        answer.push_back(sum);
    }

    for(long long ans: answer){
        cout << ans << "\n";
    }
}