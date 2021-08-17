#include<bits/stdc++.h>
using namespace std;
#define MAX 10
int N = MAX, res = 1e9;
vector<int> cnt;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
void print(){
    cout << "\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
bool check(int y, int x, int size){
    if(x + size > N || y + size > N) return false;
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(MAP[i][j] == 0) return false;
        }
    }
    return true;
}
void change(int y, int x, int size, int item){
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            MAP[i][j] = item;
        }
    }
}
void go(int y, int x, int depth){
    if(depth >= res) return;
    if(x == N){
        go(y + 1, 0, depth);
        return;
    }
    if(y == N){
        res = min(res, depth);
        return;
    }
    if(MAP[y][x] == 0){
        go(y, x + 1, depth);
        return;
    }
    for(int i = 5; i > 0; i--){
        if(cnt[i - 1] <= 0) continue;
        if(check(y, x, i)){
            cnt[i - 1]--;
            change(y, x, i, 0);
            go(y, x + i, depth + 1);
            change(y, x, i, 1);
            cnt[i - 1]++;
        }
    }
}
int main(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }
    for(int i = 0; i < 5; i++) cnt.push_back(5);
    go(0, 0, 0);
    if(res == 1e9) res = -1;
    cout << res << "\n";
}