#include<bits/stdc++.h>
using namespace std;
#define MAX 68
int N, MAP[MAX][MAX];
string input;
string go(int y, int x, int size){
    int val = MAP[y][x];
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(val != MAP[i][j]) val = -1;
        }
    }
    if(val != -1) return to_string(val);
    size /= 2;
    string ret = "";
    ret += "(" + go(y, x, size);
    ret += go(y, x + size, size);
    ret += go(y + size, x, size);
    ret += go(y + size, x + size, size) + ")";
    return ret;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < N; j++){
            MAP[i][j] = input[j] - '0';
        }
    }
    cout << go(0, 0, N) << "\n";
}