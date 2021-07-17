#include<bits/stdc++.h>
using namespace std;
#define MAX 1024
int K, treeDepth;
vector<int> arr(MAX, 0);
vector<vector<int>> answer(10, vector<int>());

void traversal(int idx, int depth, int nextIdx){
    if(depth == K) return;
    traversal(idx - nextIdx, depth + 1, nextIdx / 2);
    answer[depth].push_back(arr[idx]);
    traversal(idx + nextIdx, depth + 1, nextIdx / 2);
}

int main(){
    cin >> K;
    treeDepth = pow(2, K) - 1;
    for(int i = 0; i < treeDepth; i++){
        cin >> arr[i];
    }
    
    traversal(treeDepth / 2, 0, pow(2, K - 2));
    for(int i = 0; i < K; i++){
        for(int j = 0; j < answer[i].size(); j++){
            cout << answer[i][j] << " ";
        }
        cout <<"\n";
    }
}