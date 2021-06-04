#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    stack<int> books;
    for(int i = 0; i < N; i++){
        int weight;
        cin >> weight;
        books.push(weight);
    }

    int cnt = 0;
    while(!books.empty()){
        int box = 0;
        while(!books.empty() && box + books.top() <= M){
            box += books.top();
            books.pop();
        }
        cnt++;
    }
    cout << cnt << "\n";
}