#include<bits/stdc++.h>
using namespace std;
#define MAX 7
typedef long long ll;
ll N, B;
ll MAP[MAX][MAX];
ll ans[MAX][MAX];
void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
void op(ll X[MAX][MAX], ll Y[MAX][MAX]){
    ll target[MAX][MAX];
    memset(target, 0, sizeof(target));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                target[i][j] += X[i][k] * Y[k][j];
            }
            target[i][j] %= 1000;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            X[i][j] = target[i][j];
        }
    }
}
void multi(ll b){
    while(b > 0){
        if(b % 2){
            op(ans, MAP);
        }
        op(MAP, MAP);
        b /= 2;
    }
}
int main(){
    cin >> N >> B;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
        ans[i][i] = 1;
    }
    multi(B);
    print();
}