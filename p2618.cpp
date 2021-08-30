#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, W, x, y, dp[MAX][MAX];
vector<int> v;
struct Case{
    int y, x;
};
vector<Case> carPos(MAX);
int getDist(int here, int there){
    return abs(carPos[here].x - carPos[there].x)
         + abs(carPos[here].y - carPos[there].y);
}
void trace(){
    int a = 0, b = 1;
    for(int i = 2; i < W + 2; i++){
        if(dp[a][i] + getDist(b, i) < dp[i][b] + getDist(a, i)){
            cout << 2 << "\n";
            b = i;
        }
        else{
            cout << 1 << "\n";
            a = i;
        }
    }
}
int go(int a, int b){
	if(a == W + 1 || b == W + 1) return 0; 
	int &ret = dp[a][b];  
    if(~ret) return ret;
	int next = max(a, b) + 1;
    ret = min(go(next, b) + getDist(a, next),
	        go(a, next) + getDist(b, next));
    return ret;
}
int main(){
    cin >> N >> W;
    carPos[0] = {1, 1};
    carPos[1] = {N, N};
    for(int i = 2; i < W + 2; i++){
        cin >> x >> y; 
        carPos[i] = {y, x};
    } 
    memset(dp, -1, sizeof(dp));
	cout << go(0, 1) << '\n'; 
    trace();
}