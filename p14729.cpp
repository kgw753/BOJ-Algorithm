#include<bits/stdc++.h>
using namespace std;
int N;
double score;
priority_queue<double> pq;
vector<double> v;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> score;
        if(pq.size() == 7){
            pq.push(score);
            pq.pop();
        }
        else pq.push(score);
    }
    while(pq.size()){
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) printf("%.3f\n", v[i]);
}