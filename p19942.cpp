#include<bits/stdc++.h>
using namespace std;
int N, mp, mf, ms, mv, ans = 1e9;
int p, f, s, v, c;
struct Food{
    int p, f, s, v, c;
};
vector<Food> fd(19);
vector<int> idxs;
bool check(string tmp){
    if(idxs.empty()) return true;
    return string(idxs.begin(), idxs.end()) > tmp;
}
int main(){
    cin >> N >> mp >> mf >> ms >> mv;
    for(int i = 0; i < N; i++){
        cin >> fd[i].p >> fd[i].f >> fd[i].s >> fd[i].v >> fd[i].c;
    }
    for(int i = 1; i < (1 << N); i++){
        vector<int> tmp;
        p = f = s = v = c = 0;
        for(int j = 0; j < N; j++){
            if(i & (1 << j)){
                tmp.push_back(j + 1);
                p += fd[j].p;
                f += fd[j].f;
                s += fd[j].s;
                v += fd[j].v;
                c += fd[j].c;
            }
        }
        if(p < mp || f < mf || s < ms || v < mv) continue;
        if(ans > c || (ans == c && check(string(tmp.begin(), tmp.end())))){
            idxs = tmp;
            ans = c;
        }
    }
    if(ans == 1e9) cout << -1 << "\n";
    else{
        cout << ans << "\n";
        for(int i : idxs) cout << i << " ";
        cout << "\n";
    }
}