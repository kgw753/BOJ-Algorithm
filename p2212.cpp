#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    if(K >= N){
      cout << 0 << "\n";
      return 0;  
    } 
    vector<int> sensors(N, 0);
    vector<int> gap(N - 1, 0);

    for(int i = 0; i < N; i++){
        cin >> sensors[i];
    }

    sort(sensors.begin(), sensors.end());

    for(int i = 0; i < N - 1; i++){
        gap[i] = sensors[i + 1] - sensors[i];
    }
    
    sort(gap.begin(), gap.end());
    int answer = 0;
    for(int i = 0; i < gap.size() - (K - 1); i++){
        answer += gap[i];
    }

    cout << answer << "\n";
}