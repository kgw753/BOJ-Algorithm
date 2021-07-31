#include<bits/stdc++.h>
using namespace std;
#define MAX 15
int N, ans;
vector<int> v(MAX, 0);
bool check(int level){
    for(int i = 0; i < level; i++){
        if(v[level] == v[i] || abs(v[level] - v[i]) == level - i) return false;
    }
    return true;
}
void solve(int k){
    if(k == N) ans++;
    else{
        for(int i = 0; i < N; i++){
            v[k] = i;
            if(check(k)) solve(k + 1);
        }
    }
}
/*
 *  1. 행과 열에 각각 퀸은 하나씩 존재 할 수 있음
 *  2. 대각선에 위치할 수 없음
 *   
 *  퀸의 위치 정보를 저장하는 1차원 배열 선언 
 *  퀸의 위치 -> (idx : 행, 원소 : 열)
 *  
 */
int main(){
    cin >> N;
    solve(0);
    cout << ans << "\n";
}