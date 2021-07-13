#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int N, M;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> chickenIDX;
vector<pair<int, int>> chicken, house;
vector<int> hdist(MAX * 2, 1e9);
vector<int> dist(MAX * MAX, 0);

void combi(int k, vector<int> v){
    if(v.size() == M) {
        chickenIDX.push_back(v);
        return;
    }
    for(int i = k; i < chicken.size(); i++){
        v.push_back(i);
        combi(i + 1, v);
        v.pop_back();
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 1) house.push_back(make_pair(i, j));
            else if(MAP[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }

    combi(0, vector<int>());

    for(int i = 0; i < chickenIDX.size(); i++){
        fill(hdist.begin(), hdist.begin() + house.size(), 1e9); 
        for(int j = 0; j < chickenIDX[i].size(); j++){
            int y = chicken[chickenIDX[i][j]].first;
            int x = chicken[chickenIDX[i][j]].second;
            for(int k = 0; k < house.size(); k++){
                int dy = house[k].first;
                int dx = house[k].second;
                hdist[k] = min(hdist[k], abs(x - dx) + abs(y - dy));
            }
        }
        for(int j = 0; j < house.size(); j++) dist[i] += hdist[j];
    }

    sort(dist.begin(), dist.begin() + chickenIDX.size());
    cout << dist[0] << "\n";
}