#include<bits/stdc++.h>
using namespace std;
#define MAX 500005
int N, b, c, d;
vector<int> v(MAX, 0);
int main(){
    cin >> N;
    double sum = 0;
    for(int i = 0; i < N; i++){
        cin >> v[i];
        sum += v[i];
    }
    vector<int> check(8001, 0);
    for(int i = 0; i < N; i++) check[v[i] + 4000]++;
    int M = -1;
    for(int i = 0; i < check.size(); i++) M = max(M, check[i]);
    vector<int> bin;
    for(int i = 0; i < check.size(); i++) if(check[i] == M) bin.push_back(i - 4000);

    sort(bin.begin(), bin.end());
    sort(v.begin(), v.begin() + N);
    int c = (bin.size() > 1) ? bin[1] : bin[0];
    cout << round(sum / (double)N) << "\n";
    cout << v[N / 2] << "\n";
    cout << c << "\n";
    cout << v[N - 1] - v[0] << "\n";
}