#include<bits/stdc++.h>
using namespace std;
#define MAX 54
int N, M, input, ans = 1e9;
int MAP[MAX][MAX];
vector<pair<int, int>> chick, hom;
int getChickDist(int idx, int bm){
    int ret = 1e9;
    for(int i = 0; i < chick.size(); i++){
        if((1 << i) & bm){
            int tmp = abs(hom[idx].first - chick[i].first) + abs(hom[idx].second - chick[i].second);
            ret = min(ret, tmp);
        }
    }
    return ret;
}
int getDist(int bm){
    int dist = 0;
    for(int i = 0; i < hom.size(); i++){
        dist += getChickDist(i, bm);
    }
    return dist;
}
bool chickCnt(int bm){
    int cnt = 0;
    while(bm > 0){
        if(bm % 2) cnt++;
        bm /= 2;
    }
    return cnt > M;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
            if(MAP[i][j]){
                if(MAP[i][j] == 1) hom.push_back({i, j});
                else if(MAP[i][j] == 2) chick.push_back({i, j});
            }
        }
    }
    for(int i = 1; i < (1 << chick.size()); i++){
        int tmp = 0;
        if(chickCnt(i)) continue;
        ans = min(ans, getDist(i));
    }
    cout << ans << "\n";
}