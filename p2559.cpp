#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    vector<int> arr;
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        arr.push_back(input);
    }

    int sum = 0;
    for(int i = 0; i < K; i++) sum += arr[i];
    int M = sum;

    for(int i = K; i < N; i++){
        sum += (arr[i] - arr[i - K]);
        M = max(sum, M);
    }

    cout << M << "\n";
    
    
}