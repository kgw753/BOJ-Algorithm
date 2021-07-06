#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int H, W;
string input;
int answer[MAX][MAX];

int main(){
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        cin >> input;
        int ans = -1;
        for(int j = 0; j < input.length(); j++){
            if(input[j] == '.' && ans != -1) ans++;
            else if(input[j] == 'c') ans = 0;
            answer[i][j] = ans;
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}