#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, num, len, lowerPos = 0;
vector<int> v(MAX, 0);
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        auto lowerPos = lower_bound(v.begin(), v.begin() + len, num);
        if(*lowerPos == 0) len++;
        *lowerPos = num;
    }
    cout << len << "\n";
}