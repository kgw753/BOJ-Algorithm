#include<bits/stdc++.h>
using namespace std;
#define MAX 10
int N;
vector<int> numbers(MAX, 0);
vector<char> visited(MAX);
vector<char> op(MAX);
vector<string> answer;

bool good(int n1, int n2, char op){
    if(op == '<' && n1 < n2) return true;
    if(op == '>' && n1 > n2) return true;
    return false;
}

void dfs(int depth, string res){
    //cout << res << "\n";
    if(depth == N + 1){
        answer.push_back(res);
        return;
    }

    for(int i = 0; i <= 9; i++){
        if(visited[i] != 0) continue;
        if(res.length() == 0 || good(res[res.length() - 1] - '0', i, op[res.length() - 1])){
            visited[i] = 1;
            dfs(depth + 1, res + to_string(i));
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> op[i];
    for(int i = 0; i <= N; i++) numbers[i] = i + '0';

    dfs(0, "");
    sort(answer.begin(), answer.end());
    cout << answer[answer.size() - 1] << "\n";
    cout << answer[0] << "\n";
}