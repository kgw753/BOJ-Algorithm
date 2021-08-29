#include<bits/stdc++.h>
using namespace std;
#define MAX 4004
int N, M, u, v, c, fox[MAX], wolf[2][MAX];
vector<pair<int, int>> MAP[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(fox, fox + MAX, 1e9);
    fill(&wolf[0][0], &wolf[0][0] + 2 * MAX, 1e9);
    cin >> N >> M; // �׷��ͱ�, ���ֱ�
    for(int i = 0; i < M; i++){
        cin >> u >> v >> c; // ���, ����, �Ÿ�
        u--, v--;
        c *= 2;
        MAP[u].push_back({c, v});
        MAP[v].push_back({c, u});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    fox[0] = 0;
    while(pq.size()){
        int here = pq.top().second;
        int here_cost = pq.top().first;
        pq.pop();
        if(fox[here] != here_cost) continue;
        for(int i = 0; i < MAP[here].size(); i++){
            int there = MAP[here][i].second;
            int there_cost = MAP[here][i].first;
            if(fox[there] > fox[here] + there_cost){
                fox[there] = fox[here] + there_cost;
                pq.push({fox[there], there});
            }
        }
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq2;
    pq2.push({0, 0, 0});    // <cost, idx, type>
    wolf[0][0] = 0; // 0�� �׷��ͱ�� '�ɾ�' �� ���� cost 0 ���� ���� (������ �ٱ� ����)
    while(pq2.size()){
        int type = get<2>(pq2.top());   // 0 : �ȱ� , 1 : �ٱ�
        int here = get<1>(pq2.top());
        int here_cost = get<0>(pq2.top());
        pq2.pop();
        if(wolf[type][here] != here_cost) continue;
        for(int i = 0; i < MAP[here].size(); i++){
            int there = MAP[here][i].second;
            int there_cost = MAP[here][i].first;
            // ���� Ÿ�Կ� ���� ���� Ÿ�� ����
            if(type) there_cost *= 2;  // �޸��� -> �ȱ�
            else there_cost /= 2;   // �ȱ� -> �޸���
            if(wolf[!type][there] > wolf[type][here] + there_cost){
                wolf[!type][there] = wolf[type][here] + there_cost;
                pq2.push({wolf[!type][there], there, !type});
            }
        }
    }
    int res = 0;
    for(int i = 1; i < N; i++){
        if(fox[i] < min(wolf[0][i], wolf[1][i])) res++;
    }
    cout << res << "\n";
}