#include<bits/stdc++.h>
using namespace std;
#define MAX 500004
int N, M;
int cards[MAX];
vector<pair<int, int>> cnt;
vector<int> ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> cards[i];
    }
    sort(cards, cards + N);
    cnt.push_back({cards[0], 1});
    int now = cards[0];
    for(int i = 1; i < N; i++){
        if(cards[i] == now){
            cnt.back().second++;
        }
        else{
            now = cards[i];
            cnt.push_back({now, 1});
        }
    }
    cin >> M;
    int target;
    for(int i = 0; i < M; i++){
        cin >> target;
        int lo = 0, mid = 0, hi = cnt.size() - 1;
        int res = 0;
        while(lo <= hi){
            mid = (hi + lo) / 2;
            if(cnt[mid].first < target){
                lo = mid + 1;
            }
            else if(cnt[mid].first > target){
                hi = mid - 1;
            }
            else{
                res = cnt[mid].second;
                break;
            }
        }
        ans.push_back(res);
    }
    for(int i : ans){
        cout << i << " ";
    }
    cout << "\n";
}