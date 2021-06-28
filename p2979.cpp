#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> cost(4, 0);
    vector<int> truck(100, 0);

    for(int i = 1; i < 4; i++){
        cin >> cost[i];
    }

    for(int i = 0; i < 3; i++){
        int start, end;
        cin >> start >> end;
        for(int j = start; j < end; j++){
            truck[j]++;
        }
    }

    int res = 0;
    for(int i = 0; i <= 100; i++){
        res += cost[truck[i]] * truck[i];
    }

    cout << res << "\n";
}