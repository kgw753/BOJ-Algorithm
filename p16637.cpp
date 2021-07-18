#include<bits/stdc++.h>
using namespace std;
int N, ans = -1e9;
string input;
vector<int> numbers;
vector<char> op;
int calc(char op, int n1, int n2){
    if(op == '+') return n1 + n2;
    else if(op == '-') return n1 - n2;
    else return n1 * n2;
}
void  dfs(int depth, int value){
    if(depth == op.size()){
        ans = max(ans, value);
        return;
    }
    dfs(depth + 1, calc(op[depth], value, numbers[depth + 1]));
    if(op.size() - depth >= 2){
        int num = calc(op[depth + 1], numbers[depth + 1], numbers[depth + 2]);
        dfs(depth + 2, calc(op[depth], value, num));
    }
}
int main(){
    cin >> N;
    cin >> input;
    for(int i = 0; i < N; i++){
        if(i % 2) op.push_back(input[i]);
        else numbers.push_back(input[i] - '0');
    }
    dfs(0, numbers[0]);
    cout << ans << "\n";
}