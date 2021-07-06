#include<bits/stdc++.h>
using namespace std;
int N;
int main(){
    int num = 665;
    cin >> N;
    while(N > 0){
        if(to_string(++num).find("666") != string::npos) N--;
    }
    cout << num << "\n";
}