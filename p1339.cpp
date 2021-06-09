#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main(){
    int N;
    cin >> N;
    vector<string> input;
    vector<pair<char, int>> v;
    for(char c = 'A' ; c <= 'Z'; c++){
        v.push_back(pair<char, int>(c, 0));
    }

    for(int i = 0; i < N; i++){
        string word;
        cin >> word;
        input.push_back(word);
    }

    for(int i = 0; i < input.size(); i++){
        int len = input[i].length();
        for(int j = 0; j < len; j++){
            int plus = pow(10, len - (j + 1));
            v[input[i][j] - 'A'].second += plus;
        }
    }

    sort(v.begin(), v.end(), cmp);

    int res = 0;
    for(int i = 0; i < 10; i++){
        res += v[i].second * (9 - i);
    }
    cout << res << "\n";
}