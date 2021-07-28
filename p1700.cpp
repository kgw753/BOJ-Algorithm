#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, K, ans;
vector<int> v(MAX, 0);
vector<queue<int>> check(MAX, queue<int>());
queue<int> q;
int go(vector<int> soc){
    int idx = 0, m = -1;
    for(int i = 1; i <= K; i++){
        if(check[i].empty()){
            idx = i;
            break;
        }
        else if(check[i].front() > m){
            idx = i;
            m = check[i].front();
        }
    }
    return idx;
}
bool notHave(vector<int> soc, int item){
    for(int i = 0; i < soc.size(); i++){
        if(soc[i] == item) return false;
    }
    return true;
}
int main(){
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> v[i];
        check[v[i]].push(i);
    }
    vector<int> soc(N, 0);
    for(int i = 0; i < K; i++){
        int idx = i;
        if(soc.size() == N && notHave(soc, v[i])){
            idx = go(soc);
            check[idx].pop();
            ans++;
        }
        else{
            check[v[idx]].pop();
        }
        soc.push_back(v[i]);
    }
    cout << ans << "\n";
}