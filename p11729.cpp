#include<bits/stdc++.h>
using namespace std;
int N;
void hanoi(int num, int from, int to, int other){
    if(num == 0){
        return;
    }
    hanoi(num - 1, from, other, to);
    cout << from << " " << to << "\n";
    hanoi(num - 1, other, to, from);
}
int main(){
    cin >> N;
    cout << (1 << N) - 1 << "\n";
    hanoi(N, 1, 3, 2);
}