#include<bits/stdc++.h>
using namespace std;
int N;
string input;
vector<bool> visited('z' - 'a' + 1, false);
int main(){
    cin >> N;
    int answer = N;
    for(int i = 0; i < N; i++){
        cin >> input;
        int j = 0;
        bool ans = false;
        fill(visited.begin(), visited.end(), false);
        while(j < input.length()){
            if(visited[input[j] - 'a']){
                ans = true;
                break;
            }
            visited[input[j] - 'a'] = true;
            while(input[j] == input[j + 1]) j++;
            j++;
        }
        if(ans) answer--;
    }
    cout << answer << "\n";
}