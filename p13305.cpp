#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> data(N - 1, vector<int>(2, 0));

    int l;
    int c;

    for(int i = 0; i < N - 1; i++){
        cin >> l;
        data[i][0] = l;
    }

    for(int i = 0; i < N - 1; i++){
        cin >> c;
        data[i][1] = c;
    }

    long answer = 0;
    int min_cost = 1e9;
    for(int i = 0; i < data.size(); i++){
        min_cost = min(min_cost, data[i][1]);
        answer += long(min_cost) * data[i][0];
    }
    cout << answer << "\n";
}