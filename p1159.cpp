#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    vector<int> res('z' - 'a' + 1, 0);
    cin >> N;

    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        res[input[0] - 'a']++;
    }


    bool predaja = true;
    for(int i = 0; i < res.size(); i++){
        if(res[i] < 5) continue;
        predaja = false;
        cout << char(i + 'a');
    }
    if(predaja) cout << "PREDAJA\n";
    else cout << "\n";
}