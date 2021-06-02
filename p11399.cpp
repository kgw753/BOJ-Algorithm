#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    vector<int> waiting;
    cin >> N;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        waiting.push_back(n);
    }
    sort(waiting.begin(), waiting.end());

    int time = 0;
    int answer = 0;
    for(int i = 0; i < N; i++){
        time += waiting[i];
        answer += time;
    }

    cout << answer << "\n";
}