#include<bits/stdc++.h>
using namespace std;
int N, M, J, res;
vector<int> app;
int main(){
    cin >> N >> M >> J;

    for(int i = 0; i < J; i++){
        int a;
        cin >> a;
        app.push_back(a);
    }

    int pos = 0, mov = 0;
    for(int i = 0; i < J; i++){
        if(pos < app[i] && pos + M >= app[i]) continue;
        if(pos + M < app[i]) mov = app[i] - (pos + M);
        else mov = app[i] - pos - 1;
        pos += mov;
        res += abs(mov);
    }
    cout << res << "\n";
}