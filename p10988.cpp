#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int mid = str.length() / 2;
    
    string first = str.substr(0, mid);
    if(str.length() % 2 == 1) mid++;
    string second = str.substr(mid);
    reverse(second.begin(), second.end());

    if(first == second) cout << 1 << "\n";
    else cout << 0 << "\n";
}