#include<bits/stdc++.h>
using namespace std;
#define MAX 16
#define IDX 6
int N, ans = INT_MAX;
vector<vector<int>> MAT(MAX, vector<int>(IDX, 0));
vector<int> target(4, 0), res;

bool dicCheck(vector<vector<int>> v){
    string str1, str2;
    for(int i = 0; i < res.size(); i++) str1 += res[i];
    for(int i = 0; i < v.size(); i++) str2 += v[i][0];
    return str1 > str2;
}

bool check(vector<vector<int>> v){
    vector<int> tmp(4, 0);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < v.size(); j++){
            tmp[i] += v[j][i + 1];
        }
    }
    bool ret = true;
    for(int i = 0; i < 4; i++){
        if(tmp[i] < target[i]) ret = false;
    }
    return ret;
}

int sum(vector<vector<int>> v){
    int ret = 0;
    for(int i = 0 ; i < v.size(); i++){
        ret += v[i][5];
    }
    return ret;
}

void combi(int n, int k, vector<vector<int>> v){
    if(n == v.size()){
        int s = sum(v);
        if(check(v) && ans >= s){
            if(ans == s && dicCheck(v) == false) return;
            ans = s;
            res.clear();
            for(int i = 0; i < v.size(); i++){
                res.push_back(v[i][0]);
            }
        }
        return;
    }

    for(int i = k; i < N; i++){
        v.push_back(MAT[i]);
        combi(n, i + 1, v);
        v.pop_back();
    }
}
int main(){
    cin >> N;
    for(int i = 0; i < 4; i++) cin >> target[i];
    for(int i = 0; i < N; i++){
        MAT[i][0] = i + 1;
        for(int j = 1; j < IDX; j++){
            cin >> MAT[i][j];
        }
    }

    for(int i = 0; i <= N; i++){
        combi(i, 0, vector<vector<int>>());
    }
    if(res.empty()) ans = -1;
    cout << ans << "\n";
    for(int r : res) cout << r << " ";
    cout << "\n";
}