#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr;
    int sum = 0;
    for(int i = 0; i < 9; i++){
        int input;
        cin >> input;
        arr.push_back(input);
        sum += input;
    }

    vector<int> ans;
    int n1, n2;
    for(int i = 0; i < arr.size(); i++){
        int tmp = sum;
        for(int j = i + 1; j < arr.size(); j++){
            if(sum - (arr[i] + arr[j]) == 100){
                n1 = i;
                n2 = j; 
            }
        }
    }

    for(int i = 0; i < arr.size(); i++){
        if(i == n1 || i == n2) continue;
        ans.push_back(arr[i]);
    }
    sort(ans.begin(), ans.end());
    for(int i : ans){
        cout << i << "\n";
    }
}