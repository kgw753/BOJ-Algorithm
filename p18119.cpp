#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
int N, M, o, bm;
vector<int> wordsBit(MAX, 0);
string word;
map<char, int> mp;
char c;
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool isJaum(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return false;
    return true;
}
bool check(int bit){
    if(~bm & bit) return false;
    else return true;
}
int main(){
    fastIO();
    int n = 0;
    for(char c = 'a'; c <= 'z'; c++){
        if(isJaum(c)) mp[c] = n++;
    }
    for(int i = 0; i < mp.size(); i++) bm |= (1 << i);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> word;
        for(char c : word){
            if(isJaum(c)) wordsBit[i] |= (1 << mp[c]);
        }
    }
    for(int i = 0; i < M; i++){
        cin >> o >> c;
        if(o == 1) bm &= ~(1 << mp[c]);
        else if (o == 2) bm |= (1 << mp[c]);
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(check(wordsBit[j])) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}