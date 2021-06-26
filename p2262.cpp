#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n ; i++){
        cin >> v[i];
    }

    int answer = 0;
    for(int i = n; i > 1; i--){
        int idx = find(v.begin(), v.end(), i) - v.begin();

        int fail;
        if(idx + 1 >= v.size()){
            fail = v[idx - 1];
        }    
        else if(idx - 1 < 0){
            fail = v[idx + 1];
        }
        else{
            fail = max(v[idx + 1], v[idx - 1]);
        }

        answer += abs(i - fail);
        v.erase(find(v.begin(), v.end(), i));
    }
    cout << answer << "\n";
}