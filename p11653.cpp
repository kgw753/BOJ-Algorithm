#include<bits/stdc++.h>
using namespace std;
#define MAX 3170
int N;
vector<bool> che(MAX + 1, false);
vector<int> ans, nums;
int main(){
    cin >> N;
    int tmp = N;
    for(int i = 2; i <= tmp; i++){
        if(N == 1) break;
        while(N % i == 0){
            N /= i;
            cout << i << "\n";
        }
    }
}