#include<bits/stdc++.h>
using namespace std;
int tc, n, c;
string item, type;
vector<int> answer;

int main(){
    cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> n;
        map<string, int> m;
        for(int j = 0; j < n; j++){
            cin >> item >> type;
            m[type]++;
        }
        int r = 1;
        for(auto t: m) r *= t.second + 1; // '벗었을 때' 를 더하고 곱함
        answer.push_back(r - 1);    // '모두 벗었을 때' 를 뺌
    }
    for(int a: answer) cout << a << "\n";
}