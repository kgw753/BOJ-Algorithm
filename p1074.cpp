#include<bits/stdc++.h>
using namespace std;
int N, r, c;
int answer;
void find(int y, int x, int size){
    if(x == c && y == r){
        cout << answer << "\n";
        return;
    }
    else if(x + size > c && y + size > r && c >= x && r >= y){
        find(y, x, size / 2);
        find(y, x + size / 2, size / 2);
        find(y + size / 2, x, size / 2);
        find(y + size / 2, x + size / 2, size / 2);
    }
    else{
        answer += size * size;
    }
}

int main(){
    cin >> N >> r >> c;
    find(0, 0, (1 << N));
}