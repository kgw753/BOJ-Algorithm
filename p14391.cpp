#include<bits/stdc++.h>
using namespace std;
#define MAX 5
int N, M, ans, now, sum;
string input;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            MAP[i][j] = input[j] - '0';
        }
    }
    for(int k = 0; k < (1 << (N * M)); k++){
        sum = 0;
        for(int i = 0; i < N; i++){
            now = 0;
            for(int j = 0; j < M; j++){
                int idx = i * M + j;
                if((k & (1 << idx)) == 0){
                    now = now * 10 + MAP[i][j];
                }
                else{
                    sum += now;
                    now = 0;
                }
            }
            sum += now;
        }
        for(int i = 0; i < M; i++){
            now = 0;
            for(int j = 0; j < N; j++){
                int idx = j * M + i;
                if((k & (1 << idx)) != 0){
                    now = now * 10 + MAP[j][i];
                }
                else{
                    sum += now;
                    now = 0;
                }
            }
            sum += now;
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}