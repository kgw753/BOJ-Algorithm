#include<bits/stdc++.h>
using namespace std;

int n;
string pt;
vector<string> str;

void input(int n){
    string input;
    for(int i = 0; i < n; i++){
        cin >> input;
        str.push_back(input);
    }
}
int main(){
    cin >> n;
    cin >> pt;
    input(n);
    int pos = pt.find('*');
    string prefix = pt.substr(0, pos);
    string suffix = pt.substr(pos + 1);

    for(int i = 0; i < n; i++){
        bool res = false;
        if(pt.length() - 1 > str[i].length()){
            cout << "NE\n";
            continue;
        }

        if(prefix == str[i].substr(0, pos) &&
        suffix == str[i].substr(str[i].length() - suffix.length())) res = true;

        if(res){
            cout << "DA\n";
        }
        else{
            cout << "NE\n";
        }
    }
}