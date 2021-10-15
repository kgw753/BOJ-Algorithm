#include<bits/stdc++.h>
using namespace std;
#define MAX 54
int N, root, node, del, cnt;
vector<vector<int>> MAP(MAX, vector<int>());
void go(int node){
    int child = 0;
    for(int i : MAP[node]){
        if(i == del) continue;
        go(i);
        child++;
    }
    if(child == 0) cnt++;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> node;
        if(node == -1) root = i;
        else MAP[node].push_back(i);
    }
    cin >> del;
    if(del == root) cout << 0 << "\n";
    else{
        go(root);
        cout << cnt << "\n";
    }
}