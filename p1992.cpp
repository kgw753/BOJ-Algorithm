#include<bits/stdc++.h>
using namespace std;
#define MAX 65
int N;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
string input, result;

void search(int r, int c, int size){
    if(size == 1){
        result += (char)(MAP[r][c] + '0');
        return;
    }
    
    bool same = true;
    int tmp = MAP[r][c];
    for(int i = r; i < size + r; i++){
        for(int j = c; j < size + c; j++){
            if(tmp != MAP[i][j]){
                same = false;
                break;
            }
        }
    }

    if(same){
        result += (char)(tmp + '0');
    }
    else{
        size /= 2;
        result += '(';
        search(r, c, size);
        search(r, c + size, size);
        search(r + size, c, size);
        search(r + size, c + size, size);
        result += ')';
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < N; j++){
            MAP[i][j] = input[j] - '0';
        }
    }

    search(0, 0, N);
    cout << result << "\n";
}