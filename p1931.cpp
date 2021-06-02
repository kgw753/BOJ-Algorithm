#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    if(v1[1] == v2[1]){
        return v1[0] < v2[0];
    }
    return v1[1] < v2[1];
}

int main(){
    int N;
    cin >> N;

    vector<vector<int>> chart(N, vector<int>(2, 0));

    int start;
    int end;
    for(int i = 0; i < N; i++){
        cin >> start;
        cin >> end;
        chart[i] = {start, end};
    }
    
    sort(chart.begin(), chart.end(), cmp);

    int answer = 0;
    end = -1;
    for(int i = 0; i < N; i++){
        if(end <= chart[i][0]) {
            answer++;
            end = chart[i][1];
        }
    }
    cout << answer << "\n";
}