#include<bits/stdc++.h>
using namespace std;
#define MAX 1100000
int N;
bool che[MAX];
bool isPalin(string str){
    int len = str.length();
    string pre = str.substr(0, len / 2);
    string post = str.substr((len / 2) + (len % 2));
    reverse(post.begin(), post.end());
    return post == pre;
}
int main(){
    che[0] = che[1] = true;
    for(int i = 2; i < MAX; i++){
        if(che[i]) continue;
        for(int j = i * 2; j < MAX; j += i){
            che[j] = true;
        }
    }
    cin >> N;
    for(int i = N; i < MAX; i++){
        if(!che[i] && isPalin(to_string(i))){
            cout << i << "\n";
            break;
        }
    }
}