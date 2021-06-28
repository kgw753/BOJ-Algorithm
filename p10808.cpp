#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    vector<int> cnt('z' - 'a' + 1, 0);
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        cnt[str[i] - 'a']++;
    }

    for(int c: cnt){
        cout << c << " ";
    }
    cout << "\n";
}