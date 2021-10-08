#include<bits/stdc++.h>
using namespace std;
#define MAX 130
int N, b, w;
int MAP[MAX][MAX];
void go(int y, int x, int size){
    int now = MAP[y][x];
    bool isOne = true;
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(now != MAP[i][j]){
                isOne = false;
                break;
            }
        }
    }
    if(isOne){
        if(now == 0) w++;
        else b++;
    }
    else{
        go(y, x, size / 2);
        go(y + size / 2, x, size / 2);
        go(y, x + size / 2, size / 2);
        go(y + size / 2, x + size / 2, size / 2);
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }
    go(0, 0, N);
    cout << w << "\n";
    cout << b << "\n";
}