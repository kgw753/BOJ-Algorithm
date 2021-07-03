#include<bits/stdc++.h>
using namespace std;
int N, M;
string input;
map<string, int> nameToNum;
map<int, string> numToName;

bool isNum(string str){
    for(int i = 0; i < str.length(); i++){
        if(!isdigit(str[i])) return false;
    }
    return true;
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> input;
        nameToNum.insert(make_pair(input, i));
        numToName.insert(make_pair(i, input));
    }
    vector<string> prob(M, "");
    for(int i = 0; i < M; i++) cin >> prob[i];
    for(int i = 0; i < M; i++){
        if(isNum(prob[i])) cout << numToName[stoi(prob[i])] << "\n";
        else cout << nameToNum[prob[i]] << "\n";
    }
}