#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    getline(cin, input);
    for(int i = 0; i < input.length(); i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            if(input[i] + 13 > 'Z') input[i] -= 13;
            else input[i] += 13;
        }
        else if(input[i] >= 'a' && input[i] <= 'z'){
            if(input[i] + 13 > 'z') input [i] -= 13;
            else input[i] += 13;
        }
    }
    cout << input << "\n";
}