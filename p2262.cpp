#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> V;
void print(vector<int> v){
    for(int i = 0;i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        V.push_back(input);
    }

    int answer = 0;
    for(int i = 0; i < N - 1; i++){
        int gap = 257;
        int fail = 0;
        for(int j = 1; j < V.size(); j++){
            if(gap > abs(V[j] - V[j - 1])){
                gap = abs(V[j] - V[j - 1]);
                fail = max(V[j], V[j - 1]);
            }
        }
        
        V.erase(find(V.begin(), V.end(), fail));
        answer += gap;
    }

    cout << answer << "\n";
}