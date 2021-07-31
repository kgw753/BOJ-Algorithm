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
 *  1. ��� ���� ���� ���� �ϳ��� ���� �� �� ����
 *  2. �밢���� ��ġ�� �� ����
 *   
 *  ���� ��ġ ������ �����ϴ� 1���� �迭 ���� 
 *  ���� ��ġ -> (idx : ��, ���� : ��)
 *  
 */
int main(){
    cin >> N;
    solve(0);
    cout << ans << "\n";
}