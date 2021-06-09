#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int N, S;
vector<int> numbers;

void dfs(int depth, int value){
    for(int i = depth; i < N; i++){
        if(value + numbers[i] == S) {
            cnt++;
        }
        dfs(i + 1, value + numbers[i]);
    }
}

int main(){
    cin >> N >> S;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    dfs(0, 0);

    cout << cnt << "\n";
}