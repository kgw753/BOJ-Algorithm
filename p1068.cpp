#include<bits/stdc++.h>
using namespace std;
#define MAX 54
int N, parent, root, del;
vector<int> MAP[MAX];
int go(int node){
    int ret = 0;
    int childCnt = 0;
    for(int i = 0; i < MAP[node].size(); i++){
        if(MAP[node][i] == del) continue;
        ret += go(MAP[node][i]);
        childCnt++;
    }
    if(childCnt == 0) return 1;
    else return ret;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> parent;
        if(parent == -1) root = i;
        else MAP[parent].push_back(i);
    }
    cin >> del;
    if(del == root) cout << 0 << "\n";
    else cout << go(root) << "\n";
}