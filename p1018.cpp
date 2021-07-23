#include<bits/stdc++.h>
using namespace std;
#define MAX 51
int N, M, ans = 1e9;
string input;
vector<vector<char>> MAP(MAX, vector<char>(MAX));
int check(int y, int x){
    int ret1 = 0, ret2 = 0;
    char start1 = 'W', start2 = 'B';
    for(int i = y; i < 8 + y; i++){
        for(int j = x; j < 8 + x; j++){
            if((i + j) % 2 == 0){
                if(MAP[i][j] == start1) ret1++;
                else ret2++;
            }
            else{
                if(MAP[i][j] == start1) ret2++;
                else ret1++;
            }
        }
    }
    return min(ret1, ret2);
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            MAP[i][j] = input[j];
        }
    }
    for(int i = 0; i <= N - 8; i++){
        for(int j = 0; j <= M - 8; j++){
            ans = min(ans, check(i, j));
        }
    }
    cout << ans << "\n";
}