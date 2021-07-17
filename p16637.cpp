#include<bits/stdc++.h>
using namespace std;
#define MAX 20
int N, answer = -1e9;
string input;
vector<char> op;
vector<int> numbers;

int calc(int n1, int n2, char op){
    if(op == '+') return n1 + n2;
    else if(op == '-') return n1 - n2;
    else return n1 * n2;
}

void dfs(int depth, int num){
    if(depth == numbers.size() - 1){
        answer = max(answer, num);
        return;
    }
    int nextNum = calc(num, numbers[depth + 1], op[depth]);
    dfs(depth + 1, nextNum);
    if(numbers.size() - depth > 2){
        nextNum = calc(numbers[depth + 1], numbers[depth + 2], op[depth + 1]);
        nextNum = calc(num, nextNum, op[depth]);
        dfs(depth + 2, nextNum);
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
    cout << answer << "\n";
}