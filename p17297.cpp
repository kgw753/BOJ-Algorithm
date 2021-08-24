#include<bits/stdc++.h>
using namespace std;
#define MAX 
int M;
vector<int> v;
string blank = "Messi Messi Gimossi";
string str = " Messi Gimossi";
int main(){
    v.push_back(5), v.push_back(13);
    int i = 2;
    for(int i = 2; v[i - 1] + v[i - 2] <= pow(2, 30); i++){
        v.push_back(v[i - 1] + v[i - 2] + 1);
    }
    cin >> M;
    for(int i = v.size() - 1; i >= 1; i--){
        if(M - (v[i] + 1) >= 0) M -= (v[i] + 1);
    }
    if(M == 0 || M == 6) cout << blank << "\n";
    else cout << str[M] << "\n";
}