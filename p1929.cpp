#include<bits/stdc++.h>
using namespace std;

vector<int> era(int MIN, int MAX){
    vector<int> answer;
    vector<bool> che(MAX + 1, false);
    che[0] = true;
    che[1] = true;
    for(int i = 2; i <= MAX; i++){
        if(che[i]) continue;
        
        for(int j = i * 2; j <= MAX; j += i){
            che[j] = true;
        }
    }

    for(int i = MIN; i <= MAX; i++){
        if(!che[i]) answer.push_back(i);
    }

    return answer;
}

int main(){
    int M, N;
    cin >> M >> N;
    vector<int> answer(era(M, N));

    for(int ans: answer){
        cout << ans << "\n";
    }
}