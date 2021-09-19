#include<bits/stdc++.h>
using namespace std;
#define MAX 9
int MAP[MAX][MAX];
vector<pair<int, int>> zero;
bool rowCheck(int y, int val){
    for(int i = 0; i < MAX; i++){
        if(MAP[y][i] == val) return false;
    }
    return true;
}
bool colCheck(int x, int val){
    for(int i = 0; i < MAX; i++){
        if(MAP[i][x] == val) return false;
    }
    return true;
}
bool squareCheck(int y, int x, int val){
    int sx = x / 3 * 3;
    int sy = y / 3 * 3;
    for(int i = sy; i < sy + 3; i++){
        for(int j = sx; j < sx + 3; j++){
            if(MAP[i][j] == val) return false;
        }
    }
    return true;
}
void print(){
    cout << "\n";
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cout << MAP[i][j] << " ";
        }
        cout <<"\n";
    }
}
void go(int idx){
    if(idx == (int)zero.size()) {
        print();
        exit(0);
    }
    int y = zero[idx].first;
    int x = zero[idx].second;
    for(int i = 1; i < 10; i++){
        if(squareCheck(y, x, i) && rowCheck(y, i) && colCheck(x, i)){
            MAP[y][x] = i;
            go(idx + 1);
        }
    }
    MAP[y][x] = 0;
}
int main(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 0) zero.push_back({i, j});
        }
    }
    go(0);
}