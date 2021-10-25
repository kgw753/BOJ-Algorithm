#include<bits/stdc++.h>
using namespace std;
int N, mp, mf, ms, mv, mc = 1e9;
int p, f, s, v, cost;
priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> ans;
struct Food{
    int p, f, s, v, cost;
};
vector<Food> foods;
bool checkBal(Food food){
    if(food.f >= mf && food.p >= mp && food.s >= ms && food.v >= mv) return true;
    return false;
}
int isCorrect(int bm){
    Food tmp = {0, 0, 0, 0, 0};
    for(int i = 0; i < N; i++){
        if((1 << i) & bm){
            tmp.p += foods[i].p;
            tmp.f += foods[i].f;
            tmp.s += foods[i].s;
            tmp.v += foods[i].v;
            tmp.cost += foods[i].cost;
        }
    }
    if(checkBal(tmp)) return tmp.cost;
    else return -1;
}
vector<int> makeVec(int bm){
    vector<int> ret;
    for(int i = 0; i < N; i++){
        if((1 << i) & bm){
            ret.push_back(i + 1);
        }
    }
    return ret;
}
int main(){
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < N; i++){
        cin >> p >> f >> s >> v >> cost;
        foods.push_back({p, f, s, v, cost});
    }
    for(int i = 1; i < (1 << N); i++){
        int check = isCorrect(i);
        if(check == -1) continue;
        if(mc >= check){
            mc = check;
            ans.push({mc, makeVec(i)});
        }
    }
    if(mc == 1e9){
        cout << -1 << "\n";
    }
    else{
        cout << mc << "\n";
        for(int i : ans.top().second){
            cout << i << " ";
        }
        cout << "\n";
    }
}