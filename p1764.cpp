#include<bits/stdc++.h>
using namespace std;
int N, M;
string input;
map<string, int> a, b;
vector<string> answer;
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        a[input]++;
    }
    for(int i = 0; i < M; i++){
        cin >> input;
        b[input]++;
    }
    for(auto i: a){
        if(b[i.first]) answer.push_back(i.first);
    }
    cout << answer.size() << "\n";
    for(string s: answer) cout << s << "\n";
}