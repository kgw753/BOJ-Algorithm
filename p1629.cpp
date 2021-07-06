#include<bits/stdc++.h>
using namespace std;
long long A, B, C;
map<long, long> mem;

long long calc(long long a, long long b){
    if(mem[b]) return mem[b];
    if(b == 1){
        mem[b] = a % C;
        return a % C;
    }
    if(b % 2){
        mem[b - 1] = calc(a, b - 1);
        return (mem[b - 1] * mem[1]) % C;
    }
    else{
        mem[b / 2] = calc(a, b / 2);
        return (mem[b / 2] * mem[b / 2]) % C;
    }
}

int main(){
    cin >> A >> B >> C;
    cout << calc(A, B) << "\n";
}